#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef vector<ll> vl;
#define REP(i, a, b) for (int i = 0; i <= int(b); i++)
#define TRvi(c, it) for(vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) for(vii:iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) for(msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000
#define MEMSET_INF 127
#define MEMSET_HALF 63
#define PB push_back
int main() {
    int n;
    vi answers;
    cin >> n;
    while (n--)  {
        int x, y;

        scanf("%d%d", &x, &y);
        if(x!=1 && x!=2) {
            int j = x-2;
            int l;

            if(j%y) {
                l = j/y + 2;
            } else {
                l = j/y + 1;
            }
            answers.PB(l);
        } else {
            answers.PB(1);
        }
    }
    for(auto x : answers ) {
        cout << x << '\n';
    }
    return 0;
}