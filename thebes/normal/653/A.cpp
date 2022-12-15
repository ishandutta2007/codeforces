#include <bits/stdc++.h>
#define al(x) (x).begin(),(x).end()
#define gc(x) cin.get(x)
#define gl(x) getline(cin,x)
#define lb(x) ((x)&(-x))
#define sz(x) (int)(x.size())
#define sp ' '
#define nl '\n'
#define fi first
#define se second
using namespace std;
template<class...A>void sc(A&...a){((cin>>a),...);}
template<class...A>void pr(A...a){((cout<<a),...);}
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair<int,int> pi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;sc(n);
	set<int> s;
	for(int i=0;i<n;i++){
		int x;sc(x);
		s.insert(x);
	}
	for(int x:s){
		if(s.count(x+1)&&s.count(x+2)){
			pr("YES\n");
			return 0;
		}
	}
	pr("NO\n");
}