#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define y1 y1111111111111111111
#define pa pair<ll,ll>
#define mk make_pair
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if (ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=3000010,mod=1e9+7;
ll n,ans,cnt[4][4][4],a[2][N];
ll check(ll u,ll v,ll w,ll x,ll y,ll z){
	ll cro=(u*y-v*x%4+4)%4;
	if(cro%2)return 0;
	if ((u-x+4)%4==0&&(v-y+4)%4==0){
		if ((w+z)%4==cro&&w%2==1&&z%2==1)return 3;
		return (w+z)%4==cro;
	}else if ((u-x+4)%2==0&&(v-y+4)%2==0){
		if ((w+z+2)%4==cro&&w%2==1&&z%2==1)return 3;
		return (w+z+2)%4==cro;
	}else return (w+z+1)%2;
}
int main(){
	n=read();
	ans=0;
	For(i,1,n)a[0][i]=read(),a[1][i]=read();
	For(i,1,n){
		For(u,0,3)For(v,0,3)For(w,0,3)cnt[u][v][w]=0;
		For(j,1,n)if (j!=i){
			ll u=((a[0][j]-a[0][i])%4+4)%4,
			   v=((a[1][j]-a[1][i])%4+4)%4,
			   w=__gcd(abs(a[0][j]-a[0][i]),abs(a[1][j]-a[1][i]))%4;
			++cnt[u][v][w];
		}
		For(a0,0,63){
			ll ua=a0%4,va=a0/4%4,wa=a0/16%4;
			ans+=(ll)check(ua,va,wa,ua,va,wa)*cnt[ua][va][wa]*(cnt[ua][va][wa]-1)/2;
			For(b0,a0+1,63){
				ll ub=b0%4,vb=b0/4%4,wb=b0/16%4;
				ans+=(ll)check(ua,va,wa,ub,vb,wb)*cnt[ua][va][wa]*cnt[ub][vb][wb];
			}
		}
	}
	ans/=3;
	cout<<ans<<endl;
}