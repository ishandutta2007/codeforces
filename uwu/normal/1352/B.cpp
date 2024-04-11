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
        int n,k; cin >> n >> k;
        if (n%2==1&&k%2==0){
            cout << "NO" << '\n';
            continue;
        }
        if (n%2==1&&k%2==1){
            if (n<k){
                cout << "NO" << '\n';
                continue;
            }
            cout << "YES" << '\n';
            for (int i=1;i<k;++i){
                cout << 1 << " ";
            }
            cout << n-k+1 << '\n';
        }
        if (n%2==0&&k%2==0){
            if (n<k){
                cout << "NO" << '\n';
                continue;
            }
            cout << "YES" << '\n';
            for (int i=1;i<k;++i){
                cout << 1 << " ";
            }
            cout << n-k+1 << '\n';
        }
        if (n%2==0&&k%2==1){
            if (n<2*k){
                cout << "NO" << '\n';
                continue;
            }
            cout << "YES" << '\n';
            for (int i=1;i<k;++i){
                cout << 2 << " ";
            }
            cout << n-2*k+2 << '\n';
        }
        
    }
}