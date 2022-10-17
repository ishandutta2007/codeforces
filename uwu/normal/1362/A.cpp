#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll pows[64];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    pows[0]=1;
    for (int i=0;i<64;++i){
        pows[i]=2*pows[i-1];
    }
    while (t--){
        ll a,b; cin >> a >> b;
        if (b>a) swap(a,b);
        if (a%b==0&&__builtin_popcountll(a/b)==1){
            cout << (__builtin_popcountll((a/b)-1)+2)/3 << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
}