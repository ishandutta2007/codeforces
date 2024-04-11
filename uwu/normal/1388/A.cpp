#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        if (n<=30) cout << "NO" << '\n';
        else{
            cout << "YES" << '\n';
            int val=n-30;
            if (val==6||val==10||val==14){
                cout << "6 10 15 " << n-31 << '\n';
            }
            else cout << "6 10 14 " << n-30 << '\n';
        }
    }
}