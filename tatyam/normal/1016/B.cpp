#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define LINF (ll)1e18
#define INF (int)1e9
#define range(i) i.begin(),i.end()
#define sum(i) accumulate(range(i),0)
struct start { start() { cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10); }; }start;
inline void in() {}
template <class Head, class... Tail>
inline void in(Head&& head, Tail&&... tail) {
	cin >> head;
	in(move(tail)...);
}
template <class T>
inline void out(T t) {
	cout << t << '\n';
}
template <class Head, class... Tail>
inline void out(Head head, Tail... tail) {
	cout << head << ' ';
	out(move(tail)...);
}
template <class T>
inline void out(vector<T> a){
    rep(i,0,a.size()-1)cout<<a[i]<<' ';
    out(a.back());
}


int main() {
	int n,m,q;
	in(n,m,q);
	string s,t;
	in(s,t);
	vector<int> g(1,0);
	rep(i,0,n-m+1)g.push_back(s.substr(i,t.size())!=t?g[i]:g[i]+1);
	int a,b;
	rep(i,0,q){
	    in(a,b);
	    if(b-a+1<t.size())out(0);
	    else out(g[b-t.size()+1]-g[a-1]);
	}
}