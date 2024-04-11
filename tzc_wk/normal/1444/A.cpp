/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y10101010101
#define y0			y01010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
signed main(){
	int T;scanf("%lld",&T);
	while(T--){
		ll p,q;scanf("%lld%lld",&p,&q);
		if(p%q!=0){cout<<p<<endl;continue;}
		ll tmp=p,tmpq=q;
		vector<pair<ll,ll> > fac;
		for(int i=2;i*i<=q;i++){
			if(q%i==0){
				int cnt=0;
				while(q%i==0){
					cnt++;q/=i;
				}
				fac.pb(make_pair(i,cnt));
			}
		}
		if(q>1) fac.pb(make_pair(q,1));
		ll ans=1e18;
		for(int i=0;i<fac.size();i++){
			int x=fac[i].fi,y=fac[i].se,cnt=0;
			for(;p%x==0;){
				p/=x;cnt++;
			}
			ll mul=1;
			for(int j=1;j<=cnt-y+1;j++) mul*=x;
			ans=min(ans,mul);//cout<<mul<<endl;
		}
//		for(int i=2;i<=1000000;i++) if(p%i==0)
//			ans=min(ans,i);
		cout<<tmp/ans<<endl;
	}
	return 0;
}