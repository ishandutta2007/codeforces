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
	int n,k;
	in(n,k);
	int a,cnt=0;
	vector<int> ans(n);
	rep(i,0,n){
	    in(a);
	    cnt+=a;
	    ans[i]=cnt/k;
	    cnt-=ans[i]*k;
	}
	out(ans);
}