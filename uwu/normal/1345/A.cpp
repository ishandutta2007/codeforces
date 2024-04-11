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
        int r,c; cin >> r >> c;
        if ((r==2&&c==2)||r==1||c==1){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
}