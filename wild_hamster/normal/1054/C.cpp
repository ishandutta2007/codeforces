#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
int a[10050], b[10050], used[10050], d[10050];
vector<int> f;
int Abs(int x) {
    return (x>0?x:-x);
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    int p = 0, cnt = 0;
    while(1) {
        f.clear();
        int r = 0;
        for (int i = 0; i < n; i++)
            r += used[i];
        if (r == n)
            break;
        for (int i = 0; i < n; i++)
            if (!used[i] && a[i] == 0 && b[i] == 0) {
                used[i] = 1;
                f.push_back(i);
            }
        if (f.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        for (int i = 0; i < f.size(); i++) {
            int x = f[i];
            d[x] = p;
            for (int j = 0; j < x; j++)
                if (!used[j])
                    b[j]--;
            for (int j = x+1; j < n; j++)
                if (!used[j])
                    a[j]--;
        }
        for (int i = 0; i < n; i++)
        if (a[i] < 0 || b[i] < 0) {
            cout << "NO" << endl;
            return 0;
        }
        p--;
        cnt++;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << d[i]+cnt << " ";
    return 0;
}