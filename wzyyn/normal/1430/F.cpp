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
const int N=2005;
int n,k;
int l[N],r[N],a[N];
ll f[N];
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d%d",&l[i],&r[i],&a[i]);
	memset(f,33,sizeof(f));
	f[0]=0;
	ll ans=1ll<<60;
	For(i,1,n){
		int nT=l[i];
		ll cost=k,Bul=k;
		For(j,i,n){
			if (!Bul&&l[j]!=r[j-1])	Bul=k,cost+=k;
			//cout<<i<<' '<<j<<' '<<Bul<<' '<<cost<<endl; 
			if (Bul+1ll*(r[j]-l[j])*k<a[j]) break;
			int v=min(Bul,1ll*a[j]),rem=a[j];
			Bul-=v; rem-=v;
			int round=(rem+k-1)/k;
			cost+=1ll*round*k;
			Bul+=1ll*round*k;
			Bul-=rem;
			//cout<<i<<' '<<j<<' '<<Bul<<' '<<cost<<' '<<round<<endl;
			if (r[j]!=l[j+1]||round!=r[j]-l[j]){
				if (j==n) ans=min(ans,f[i-1]+cost-Bul);
				f[j]=min(f[j],f[i-1]+cost);
			}
			if (round!=r[j]-l[j]&&!Bul)
				Bul+=k,cost+=k;
		}
	}
	if (ans>1ll<<58)
		ans=-1;
	cout<<ans<<endl;
}