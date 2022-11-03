#include<bits/stdc++.h>
using namespace std;
#define ll int
#define ld long double
#define For(i,x,y) for(ll i = (x);i <= (y);++i)
#define FOr(i,x,y) for(ll i = (x);i >= (y);--i)
#define rep(i,x,y) for(ll i = (x);i < (y);++i)
#define fi first
#define se second
#define pa pair<ll,ll>
#define mk make_pair
#define pb push_back
#define clr(a,b) memset(a,b,sizeof(a))
#define cpy(a,b) memcpy(a,b,sizeof(b))
#define y1 y11111111111111111111
#define debug puts("@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}
const ll N=5000100;
vector<pa>mp[N];
vector<ll>sum[N];
ll pos[N],a[N],n,ans=-1,a1,a2,a3,a4;
int main(){
	n=read();
	For(i,1,n)a[i]=read(),sum[a[i]].pb(i);
	n=0;
	For(i,1,2500000)if (sum[i].size()>=4){
		puts("YES");
		cout<<sum[i][0]<<' '<<sum[i][1]<<' '<<sum[i][2]<<' '<<sum[i][3]<<endl;
		return 0;
	}else if (sum[i].size()>=2){
		if (!a1)a1=sum[i][0],a2=sum[i][1];
		else{
			puts("YES");
			cout<<a1<<' '<<sum[i][0]<<' '<<a2<<' '<<sum[i][1]<<endl;
			return 0;
		}
		a[++n]=i;
		pos[n]=sum[i][0];
		a[++n]=i;
		pos[n]=sum[i][1];
	}else if (sum[i].size()>=1)a[++n]=i,pos[n]=sum[i][0];
	For(i,1,n)For(j,i+1,n){
		ll x=a[i]+a[j];
		rep(k,0,mp[x].size()){
			if ((mp[x][k].fi!=i)&&(mp[x][k].se!=i)&&(mp[x][k].fi!=j)&&(mp[x][k].se!=j)){
				puts("YES");
				cout<<pos[mp[x][k].fi]<<' '<<pos[mp[x][k].se]<<' '<<pos[i]<<' '<<pos[j]<<endl;
				return 0;
			}
		}
		mp[x].pb(mk(i,j));
	}
	puts("NO");
}