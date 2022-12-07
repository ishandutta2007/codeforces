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
const int N=1000005;
const int M=(1<<12)|5;
int n,times[M],q[M];
ll K,di[15],val[15],tms[M];
ll f[2][15][M];
pll a[N];
map<ll,int> mp;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void divide(ll x){
	for (int i=2;1ll*i*i<=x;i++)
		if (x%i==0){
			di[++*di]=i;
			for (;x%i==0;x/=i);
		}
	if (x!=1)
		di[++*di]=x;
}
int main(){
	scanf("%d%lld",&n,&K);
	For(i,1,n) scanf("%lld",&a[i].se);
	For(i,1,n) scanf("%lld",&a[i].fi);
	sort(a+1,a+n+1);
	ll G=a[1].se;
	For(i,1,n) G=gcd(G,a[i].se);
	divide(G);
	memset(f,30,sizeof(f));
	f[0][0][0]=0;
	//cout<<G<<endl;
	//For(i,1,*di) cout<<di[i]<<endl;
	For(i,1,n){
		ll x=a[i].se;
		For(j,1,*di){
			val[j]=1;
			for (;x%di[j]==0;){
				x/=di[j];
				val[j]*=di[j];
			}
		}
		ll used=a[i].se/x;
		//cout<<a[i].se<<' '<<used<<endl;
		if ((++mp[used])>(*di)) continue;
		For(j,0,(1<<(*di))-1) tms[j]=(j==0?1:0);
		For(j,1,*di) tms[1<<(j-1)]=val[j];
		For(j,0,(1<<(*di))-1){
			tms[j]=tms[j-(j&(-j))]*tms[j&(-j)];
			if (tms[j]<=K&&(++times[j]<=(*di))){
				q[++*q]=j;
				//cout<<i<<' '<<j<<' '<<a[i].fi<<endl;
				int rem=(1<<(*di))-1-j;
				for (int k=rem;;k=(k-1)&rem){
					For(l,0,(*di))
						f[1][l+1][k|j]=min(f[1][l+1][k|j],f[0][l][k]+a[i].fi);
					if (k==0) break;
				}
			}
		}
		For(j,1,*q){
			int rem=(1<<(*di))-1-q[j];
			for (int k=rem;;k=(k-1)&rem){
				For(l,0,(*di))
					f[0][l][q[j]|k]=min(f[0][l][q[j]|k],f[1][l][q[j]|k]);
				if (k==0) break;
			}
		}
		//cout<<i<<endl;
		*q=0;
	}
	ll ans=(1ll<<60);
	For(i,0,(*di))
		if (f[0][i][(1<<(*di))-1]<=(1ll<<50)){
			//cout<<i<<' '<<f[0][i][(1<<(*di)-1)]<<endl;
			ans=min(ans,i*f[0][i][(1<<(*di))-1]);
		}
	if (ans>(1ll<<50)) puts("-1");
	else printf("%lld\n",ans);
} 
/*
1->66 64+2
2->33 32+1
3->12 8+12
*/