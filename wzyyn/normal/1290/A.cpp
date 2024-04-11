#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
int n,m,k,ans;
int a[10005],b[10005];
int main(){
	int T;
	scanf("%d",&T);
	while (T--){ 
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		For(i,1,n) scanf("%d",&a[i]);
		For(i,n+1,2*n) a[i]=-(1<<30);
		For(i,1,n) b[i]=max(a[i],a[i+(n-m)]);
		For(p,0,min(m-1,k)){
			int pl=p+1,pr=pl+max(0,m-1-k),v=1<<30;
			For(j,pl,pr) v=min(v,b[j]);
			ans=max(ans,v);
		}
		printf("%d\n",ans);
	}
}