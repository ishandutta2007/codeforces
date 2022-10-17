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
        int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
        if ((a-b)*n<=c+d&&(a+b)*n>=c-d) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}