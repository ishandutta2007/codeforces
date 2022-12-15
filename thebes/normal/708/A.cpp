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

char sf(char c){
	c--;
	if(c<'a')c+=26;
	return c;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	string s;sc(s);
	for(int i=0;i<sz(s);i++){
		if(s[i]!='a'){
			for(int j=i;j<sz(s);j++){
				if(sf(s[j])<s[j])s[j]=sf(s[j]);
				else break;
			}
			pr(s,nl);
			return 0;
		}
	}
	s[sz(s)-1]=sf(s[sz(s)-1]);
	pr(s,nl);
}