#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#define lowbit(x) (x&-x)
using namespace std;
const int maxn=500005;
int n,m,tot,ans;
int t[maxn],a[maxn],b[maxn],num[maxn];
map<int,int>mp;
vector<int>V;
void update(int x,int v){
	for(int i=x;i<=tot;i+=lowbit(i)){
		if(t[i]==0)
			V.emplace_back(i);
		t[i]=max(t[i],v);
	}
}
int query(int x){
	int res=0;
	for(int i=x;i;i-=lowbit(i))
		res=max(res,t[i]);
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]-=i,num[i]=a[i];
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(num+1,num+1+n);
	for(int i=1;i<=n;i++)
		if(i==1||num[i]!=num[i-1])
			mp[num[i]]=++tot;
	for(int i=1;i<=n;i++)
		a[i]=mp[a[i]];
	b[m+1]=n+1,a[n+1]=tot+1;
	for(int i=1;i<m;i++)
		if(a[b[i]]>a[b[i+1]]){
			puts("-1");
			return 0;
		}
	for(int i=0;i<=m;i++){
		int p=b[i]+1,q=b[i+1]-1;
		if(p<=q){
			int mx=0;
			for(int j=p;j<=q;j++)
				if(a[b[i]]<=a[j]&&a[j]<=a[b[i+1]]){
					int f=query(a[j])+1;
					mx=max(mx,f),update(a[j],f);
				}
			ans+=(q-p+1)-mx;
			while(!V.empty())
				t[V.back()]=0,V.pop_back();
		}
	}
	printf("%d\n",ans);
	return 0;
}