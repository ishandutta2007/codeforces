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
        int n,x; cin >> n >> x;
        int odd=0,even=0;
        for (int i=0,a;i<n;++i){
            cin >> a;
            if (a%2==0) even++;
            else odd++;
        }
        if (x==n&&odd%2==0) cout << "no" << '\n';
        else if (odd==0) cout << "no" << '\n';
        else if (even==0&&x%2==0) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }
}