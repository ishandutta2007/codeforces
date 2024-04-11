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
int n,mo,k;
int a[300005];
int main(){
	scanf("%d%d%d",&n,&mo,&k);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		a[i]=(1ll*x*x%mo*x%mo*x%mo+mo-1ll*k*x%mo)%mo;
	}
	sort(a+1,a+n+1);
	ll s=0,ans=0;
	For(i,1,n){
		s=(a[i]==a[i-1]?s+1:1);
		ans+=s-1;
	}
	printf("%d\n",ans);
}