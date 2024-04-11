#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define LINF (ll)1e18
#define INF (int)1e9
#define range(i) i.begin(),i.end()
#define Yes(i) out(i?"Yes":"No");return 0
struct aaa{aaa(){cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(10);};}aaaaaaa;
inline void in() {}
template <class Head, class... Tail>
inline void in(Head&& head,Tail&&... tail){
    cin>>head;
    in(move(tail)...);
}
template <class T>
inline void out(T t) {
    cout<<t<<'\n';
}
template <class Head, class... Tail>
inline void out(Head head,Tail... tail){
    cout<<head<<' ';
    out(move(tail)...);
}

int main(){
    int n;
    in(n);
    vector<int>a(n),b(n);
    rep(i,0,n)in(a[i]);
    rep(i,0,n)in(b[i]);
    Yes(accumulate(a.begin(), a.end(), 0)>=accumulate(b.begin(), b.end(), 0));
}