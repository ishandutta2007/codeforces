#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,l,r) for(ll i=l;i<r;i++)
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
    string s;
    in(s);
    int one=0;
    rep(i,0,s.size())if(s[i]=='1'){
        one++;
        s.erase(s.begin()+i);
        i--;
    }
    s+='2';
    rep(i,0,s.size())if(s[i]=='2'){
        s.insert(i, one, '1');
        break;
    }
    s.pop_back();
    out(s);
}