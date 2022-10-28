#include <bits/stdc++.h>
using namespace std;

#define rep(i, n)    for(int i = 0; i < (n); ++i)
#define repA(i, a, n)  for(int i = a; i <= (n); ++i)
#define repD(i, a, n)  for(int i = a; i >= (n); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fill(a)  memset(a, 0, sizeof (a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi divs[1000009];
bool p[1000009];
vi primes;
void pre(){
	repA(i,2,1000000){
		if(!p[i]) {
			primes.pb(i);
			for(int j= i;j<=1000000;j+=i) divs[j].pb(i),p[j] = true;
		}
	}
}
int L(int x,int p){
	int s = sz(divs[p]);
	int tot = (1<<s)-1;
	ll ans =0;
	repA(i,1,tot){
		int cnt=0;
		int var =1;
		rep(j,s) if(i&(1<<j)) cnt++,var*=divs[p][j];
		if(cnt%2) ans+=x/var;
		else ans-=x/var;
	}
	return x-ans;
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	pre();	
	int q;cin>>q;
	rep(aa,q){
		int x,p,k;cin>>x>>p>>k;
		if(p==1) cout<<k+x<<'\n';
		else{
			k+=L(x,p);
			int l = 1,r=1e8;
			while(l<r){
				int m = (l+r)>>1;
				if(L(m,p)>=k) r = m;
				else l=m+1;
			}
			cout<<l<<'\n';
		}
	}
	return 0;
}