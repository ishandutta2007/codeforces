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
#define int ll
    int n;
    in(n);
    vector<int>a(n*2);
    rep(i,0,n*2)in(a[i]);
    sort(a.begin(), a.end());
    int min=(a[n-1]-a[0])*(a[n*2-1]-a[n]);
    rep(i,1,n)if(min>(a[n*2-1]-a[0])*(a[i+n-1]-a[i]))min=(a[n*2-1]-a[0])*(a[i+n-1]-a[i]);
    out(min);
}