#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
constexpr int max_n=200000;
pair<int,int>a[max_n+1];
bool cmp(const int&x,const pair<int,int>&y){
	return x<y.first;
}
bool cmp2(const int&x,const pair<int,int>&y){
	return x<y.second;
}
int mxr[max_n+1];
int nxt[max_n+1][32-__builtin_clz(max_n)];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&a[i].first,&a[i].second);
	sort(a+1,a+n+1);
	int now=1;
	for(int i=2; i<=n; ++i){
		if(a[i].second<=a[now].second)
			continue;
		if(a[i].first==a[now].first)
			a[now]=a[i];
		else
			a[++now]=a[i];
	}
	n=now;
	mxr[n]=n;
	for(int i=n; --i; )
		mxr[i]=a[i+1].first<=a[i].second?mxr[i+1]:i;
	int k=0;
	for(; (1<<k)<n; ++k);
	--k;
	for(int i=n,j=n; i; --i){
		while(a[j].first>a[i].second)
			--j;
		int now=nxt[i][0]=j;
		for(int j=1; j<=k; ++j)
			nxt[i][j]=now=nxt[now][j-1];
	}
	for(int l,r; m; --m){
		scanf("%d%d",&l,&r);
		int pos=upper_bound(a+1,a+n+1,l,cmp)-a-1,ans=1;
		if(pos==0||a[pos].second<=l||a[mxr[pos]].second<r){
			puts("-1");
			goto failed;
		}
		for(int j=k; j>=0; --j)
			if(a[nxt[pos][j]].second<r)
				ans+=1<<j,pos=nxt[pos][j];
		if(a[pos].second<r)
			++ans;
		printf("%d\n",ans);
		failed:;
	}
	return 0;
}