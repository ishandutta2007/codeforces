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

const int N=150005;
vector<int> a(N);
int n;

bool ok(int i){
	//pr("call ",i,nl);
	//for(int _=0;_<n;_++)pr(a[_],sp);
	//pr(nl);
	bool ret=true;
	if(i&1){ //peak
		if(i-1>=0)ret&=a[i]>a[i-1];
		if(i+1<n)ret&=a[i]>a[i+1];
	}
	else { //trough
		if(i-1>=0)ret&=a[i]<a[i-1];
		if(i+1<n)ret&=a[i]<a[i+1];
	}
	//pr("return ",ret,nl);
	return ret;
}

int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	sc(n);
	for(int i=0;i<n;i++)sc(a[i]);
	vector<int> bad;
	for(int i=0;i<n;i++){
		if(!ok(i))bad.push_back(i);
	}
	if(sz(bad)>10){pr(0,nl);return 0;} //arbitrary for now
	set<pi> vd; //valid swaps
	for(int i:bad){//try swapping bad one with something
		for(int j=0;j<n;j++){
			if(j==i)continue;
			//pr("swap ",i,sp,j,nl);
			swap(a[i],a[j]);
			//does it fix the issues?
			bool yes=true;
			for(int x:bad)yes&=ok(x);
			yes&=ok(j);
			if(yes){
				if(i>j)vd.emplace(j,i);
				else vd.emplace(i,j);
			}
			swap(a[i],a[j]); //undo
			//for(int _=0;_<n;_++)pr(a[_],sp);
			//pr(nl);
		}
	}
	//for(pi p:vd)pr(p.fi,sp,p.se,nl);
	pr(sz(vd),nl);
}