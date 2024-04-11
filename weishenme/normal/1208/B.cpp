#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
const int N=2005;
vector<int > v[N];
int a[N],b[N],c[N],n,m,ans=1e9,cnt[N],Q,x,y,opt;
char s[N];
int ef(int x){
	int l=1,r=m;
	while (l<r){
		int mid=(l+r)/2;
		if (b[mid]<x)l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);m=1;
	for (int i=2;i<=n;i++)
		if (b[i]!=b[m])b[++m]=b[i];
	for (int i=1;i<=n;i++)a[i]=ef(a[i]);	
	for (int i=1;i<=n;i++){
		memset(cnt,0,sizeof cnt);
		int flag=0;
		for (int j=1;j<=n;j++){
			cnt[a[j]]++;
			flag+=cnt[a[j]]>1;
		}
		int j=i;
		while (flag&&j<=n){
			flag-=cnt[a[j]]>1;
			cnt[a[j]]--;
			j++;
		}
		if (!flag)ans=min(ans,j-i);
	}
	printf("%d\n",ans);
}