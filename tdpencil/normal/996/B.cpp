#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define REP(i, a, b) for (int i = 0; i <= int(b); i++)
#define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for(vii:iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF 63
#define PB push_back
int main(){
    int n, ans=0, rounds=0;
    vi q;
    cin >> n;
    for(int i = 0; i < n; i++ ) {
        int x; cin >> x; q.PB(x);
    }
    while(true) {
        for(int i = 0; i < q.size(); i++) {
            if((q[i]-rounds)<=0) {
                ans=i+1;
                cout << ans;
                return 0;
            } else {
                rounds++;
            }
        }
    }
    return 0;
}