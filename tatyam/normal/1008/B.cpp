#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
#define INF (ll)1e18
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
    int n,height;
    in(n);
    int x,y;
    in(x,y);
    height=max(x,y);
    rep(i,1,n){
        in(x,y);
        if(x<y)swap(x,y);
        if(height>=x)height=x;
        else if(height>=y)height=y;
        else {out("NO");return 0;}
    }
    out("YES");
}