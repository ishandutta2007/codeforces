#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 3e5, M = 1e6;
mt19937 rng(time(0));

int T, n;
LL a[N + 5];

int main() {
    cin >> T;

    rep(cas, 1, T) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        if(n==1){
            cout << "T\n";
        }else if(n==2){
            cout << (a[1] != a[2] ? "T\n" : "HL\n");
        }else{
            sort(a + 1, a + n + 1);
            int sum = 0;
            rep(i, 1, n - 1) sum += a[i];
            if(sum<a[n]){
                cout << "T\n";
            }else{
                sum += a[n];
                cout << (sum % 2 ? "T\n" : "HL\n");
            }
        }
    }
    return 0;
}