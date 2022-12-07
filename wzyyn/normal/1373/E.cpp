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
#define all(v) v.begin(),v.end()
using namespace std;

void mian(){
	int n,k;
	cin>>n>>k;
	ll ans=1ll<<60;
	For(d,0,9) For(l,0,16){
		int dif=0;
		For(p,0,k)
			if (p+d<=9) dif+=p;
			else dif+=p-9*(l+1);
		if (n-dif<0||(n-dif)%(k+1)) continue;
		int v=(n-dif)/(k+1);
		if (v<d+l*9||v>150) continue;
		ll p=0,pw=1;
		//cout<<d<<' '<<l<<' '<<v<<endl;
		p+=d*pw; v-=d; pw*=10;
		//cout<<p<<' '<<pw<<endl;
		For(j,1,l) p+=9*pw,v-=9,pw*=10;
		int xi=min(v,8);
		p+=xi*pw,v-=xi,pw*=10;
		for (;v;){
			int xi=min(v,9);
			p+=xi*pw,v-=xi,pw*=10;
		}
		ans=min(ans,p);
	}
	if (ans==1ll<<60) ans=-1;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) mian();
}