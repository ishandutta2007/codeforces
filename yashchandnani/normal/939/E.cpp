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
typedef long double ld;
ld ans;
int cnt;
void add(int val){
	ans = (ans*cnt+val)/(cnt+1);
	cnt++;
}
void rem(int val){
	ans = (ans*cnt-val)/(cnt-1);
	cnt--;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int q;cin>>q;
	vi v;
	cout<<setprecision(20);
	q--;int t,val;cin>>t>>val;
	ans=val;v.pb(val);cnt++;
	rep(aa,q){
		int t;cin>>t;
		if(t==1){
			int val;cin>>val;
			add(val);
			rem(v.back());
			v.pb(val);
			while(cnt<sz(v)&&ans>v[cnt-1]){
				add(v[cnt-1]);
			}
		}
		else{
			cout<<v.back()-ans<<'\n';
		}
	}
	return 0;
}