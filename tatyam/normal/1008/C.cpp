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
    int n;
    in(n);
    vector<int>a(n);
    rep(i,0,n)in(a[i]);
    sort(a.begin(),a.end());
    int at=n-1,ans=0;
    for(int i=n-1;i>=0;--i){
        while (a[i]<=a[at]&&at>=0) {
            at--;
        }
        if(at<0)break;
        ans++;
        at--;
    }
    out(ans);
}