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
ll l(int x){
	return 1ll*x*x-1ll*(x/2)*(x/2);
}
ll r(int x){
	return 1ll*x*x-1;
}
ll cal(int a,int b){
	return 1ll*a*a-1ll*b*b;
}
int check(int v,ll x){
	int s = sqrt(v);
	repA(i,1,s){
		if(cal(v,v/i)==x) return i;
	}
	repA(i,1,s){
		if(cal(v,i)==x){
			if(v/(v/i)==i) return (v/i);
			if(v/((v+i-1)/i)==i) return (v+i-1)/i;
		}
	}
	return -1;
}
void solve(ll x){
	int lo = 2 ,hi = 1e9+1;
	while(lo<hi){
		int m = (lo+hi)>>1;
		if(l(m)<=x){
			lo = m+1;
		}
		else hi = m;
	}
	int ub = lo;
	lo = 2,hi=1e9+1;
	while(lo<hi){
		int m = (lo+hi)>>1;
		if(r(m)<x){
			lo = m+1;
		}
		else hi = m;
	}
	int lb = lo;
	int ans = -1;
	while(lb<ub){
		ans = check(lb,x);
		if(ans!=-1) break;
		lb++;
	}
	if(lb==ub) cout<<-1<<'\n';
	else cout<<lb<<' '<<ans<<'\n';
}
int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;cin>>t;
	rep(i,t){
		int x;cin>>x;
		if(x==0){
			cout<<"1 1\n";
		}
		else solve(x);
	}
	return 0;
}