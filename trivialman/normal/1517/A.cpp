#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 998244353;
const int N = 5005;

int n, T;
LL x;

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> T;
	while(T--){
        cin >> x;
        if(x%2050ll){
            cout << "-1\n";
            continue;
        }
        x /= 2050ll;
        int ans = 0;
        while(x){
            ans += x % 10;
            x /= 10;
        }
        cout << ans << endl;
    }
    return 0;
}