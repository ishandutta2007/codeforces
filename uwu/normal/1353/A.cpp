#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n,m; cin >> n >> m;
        if (n==1){
            cout << 0 << '\n';
            continue;
        }
        if (n==2){
            cout << m << '\n';
            continue;
        }
        if (n>=3){
            cout << 2*m << '\n';
            continue;
        }
    }
}