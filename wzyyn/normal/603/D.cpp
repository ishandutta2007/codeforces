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
int n,dx[N],dy[N],len[N];
map<pll,int> mp;
ll ans;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dx[i]=a*c; dy[i]=b*c;
		len[i]=a*a+b*b;
	}
	For(i,1,n){
		mp.clear();
		For(j,i+1,n){
			ll Dx=1ll*dx[i]*len[j]-1ll*dx[j]*len[i];
			ll Dy=1ll*dy[i]*len[j]-1ll*dy[j]*len[i];
			if (!Dx&&!Dy) ans+=n-i-1;
			else{
				//cout<<i<<' '<<j<<' '<<Dx<<' '<<Dy<<endl;
				if (Dx<0||(!Dx&&Dy<0)) Dx*=-1,Dy*=-1;
				ll G=gcd(Dx,abs(Dy)); Dx/=G; Dy/=G;
				ans+=mp[pll(Dx,Dy)];
				++mp[pll(Dx,Dy)];
			}
		}
	}
	printf("%lld\n",ans);
}