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
	ld h,m,s,t1,t2;sc(h,m,s,t1,t2);
	h*=5;t1*=5;t2*=5;
	m+=s/60;
	h+=m/60*5;
	if(h>=60)h-=60;
	if(m>=60)m-=60;
	if(t1>=60)t1-=60;
	if(t2>=60)t2-=60;
	vector<ld> v={h,m,s,t1,t2};
	sort(al(v));
	for(int i=0;i<sz(v);i++){
		ld cur=v[i],nxt=v[(i+1)%sz(v)];
		if((cur==t1&&nxt==t2)||(nxt==t1&&cur==t2)){
			pr("yes\n");
			return 0;
		}
	}
	pr("no\n");
}