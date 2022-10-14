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
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2;
ll a[100500], b[100500], ans[100500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        int x = b[i];
        int flag = 0;
        for (int j = x; j >= 0; j -= i)
            if (ans[j] == 0 && a[j] > i)
                flag = 1;
        for (int j = x; j < n; j += i)
            if (ans[j] == 0 && a[j] > i)
                flag = 1;
        ans[b[i]] = flag;
    }
    string s;
    for (int i = 0; i < n; i++)
        if (ans[i])
            s.push_back('A');
        else
            s.push_back('B');
    cout << s << endl;
    return 0;
}