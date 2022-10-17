#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    int n, k;
    cin >> n >> k;
    int lo = k / 2, hi = k / 2 * 3;
    int y;
    cout << "? " << 1 << endl; cin >> y;
    for(int i=1;i<=999;++i) {
        int x = mrand() % n;
        cout << "? " << x + 1 << endl;
        cin >> y;
        if(y != k) {
            if(y < k) {
                int last = y;
                while(1) {
                    x = (x + 1) % n;
                    cout << "? " << x + 1 << endl;
                    cin >> y;
                    if(y == k) {
                        cout << "! " << x + 1 << endl;
                        return 0;
                    }
                    last = y;
                }
            } else {
                int last = y;
                while(1) {
                    x = (x + n - 1) % n;
                    cout << "? " << x + 1 << endl;
                    cin >> y;
                    if(y == k) {
                        cout << "! " << x + 1 << endl;
                        return 0;
                    }
                    last = y;
                }
            }
        }
    }
    assert(0);
}