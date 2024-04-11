#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int mo=998244353;
const int N=1005;
int a[N],pre[N];
int n,k,ans,f[N],g[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	For(i,1,100000/(k-1)){
		int pos=0;
		For(j,1,n){
			for (;a[j]-a[pos+1]>=i;++pos);
			pre[j]=pos;
		}
		For(j,1,n) f[j]=1;
		For(j,2,k){
			For(p,1,n) g[p]=(g[p-1]+f[p])%mo;
			For(p,1,n) f[p]=g[pre[p]];
		}
		For(j,1,n)
			ans=(ans+f[j])%mo;
	}
	printf("%d\n",ans);
}