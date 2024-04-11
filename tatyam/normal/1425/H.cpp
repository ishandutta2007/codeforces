#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template<class T> bool chmin(T& a,T b){if(a>b) {a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b){if(a<b) {a = b; return true;} return false;}
#define all(x) (x).begin(),(x).end()
#define debug(x)  cerr << #x << " = " << (x) << endl;

void solve(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    bool neg = (A+B)%2;
    bool no_large = A==0 && D==0;
    bool no_small = B==0 && C==0;
    if(neg && !no_large) cout << "Ya ";
    else cout << "Tidak ";
    if(neg && !no_small) cout << "Ya ";
    else cout << "Tidak ";
    if(!neg && !no_small) cout << "Ya ";
    else cout << "Tidak ";
    if(!neg && !no_large) cout << "Ya\n";
    else cout << "Tidak\n";

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}