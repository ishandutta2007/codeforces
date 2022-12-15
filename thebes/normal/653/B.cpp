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

string s;
int n,q,ans;
map<string,string> op;

void chk(){
	//pr("call ",s,nl);
	string tmp=s;
	while(sz(tmp)>1){
		string hv=tmp.substr(0,2);
		if(op.find(hv)==op.end())return;
		tmp.replace(0,2,op[hv]);
		//pr(tmp,nl);
	}
	if(tmp=="a")ans++;
}

void go(int d=0){
	if(d==n)chk();
	else{
		for(char c='a';c<='f';c++){
			s.push_back(c);
			go(d+1);
			s.pop_back();
		}
	}
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	sc(n,q);
	while(q--){
		string u,v;sc(u,v);
		op[u]=v;
	}
	go();
	pr(ans,nl);
}