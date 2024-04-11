#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
set<ll> lifts;
set<ll> elevators;
pii a[300500];
vector<pii> f1, f2;
int main() {
    //freopen("input.txt","r",stdin);
    ll n,x1,x2;
    cin >> n >> x1 >> x2;
    for (int i = 0; i < n; i++) {
        scanf("%d",&a[i].X);
        a[i].Y = i+1;
    }
    sort(a, a+n);
    ll lst;
    lst = -100500;
    for (int i = 1; i <= n; i++) {
        if (1) {
            ll pos1 = upper_bound(a, a+n, mp((x1-1)/i+1, -1))-a;
            lst = (x1-1)/i+1;
            if (i+pos1 <= n)
                f1.push_back(mp(i, pos1));
        }
    }

    lst = -100500;
    for (int i = 1; i <= n; i++) {
        if (1) {
            ll pos2 = upper_bound(a, a+n, mp((x2-1)/i+1, -1))-a;
            lst = (x2-1)/i+1;
            if (i+pos2 <= n)
                f2.push_back(mp(i, pos2));
        }
    }
    if (f1.empty() || f2.empty()) {
        cout << "No" << endl;
        return 0;
    }

    for (int i = 0; i < f1.size(); i++) {
        ll pos1 = f1[i].Y;
        ll v1 = f1[i].X;
        ll pos2 = f2[0].Y;
        ll v2 = f2[0].X;
        if (min(pos1, pos2) + v1 + v2 <= n) {
            cout << "Yes" << endl;
            cout << v1 << " " << v2 << endl;
            if (pos1 < pos2) {
                for (int i = pos1; i < pos1 + v1; i++)
                    cout << a[i].Y << " ";
            } else {
                for (int i = max(pos1,pos2+v2); i < max(pos1,pos2+v2)+v1; i++)
                    cout << a[i].Y << " ";
            }
            cout << endl;

            if (pos2 <= pos1) {
                for (int i = pos2; i < pos2 + v2; i++)
                    cout << a[i].Y << " ";
            } else {
                for (int i = max(pos2,pos1+v1); i < max(pos2,pos1+v1)+v2; i++)
                    cout << a[i].Y << " ";
            }
            cout << endl;
            return 0;
        }
    }

    for (int i = 0; i < f2.size(); i++) {
        ll pos2 = f2[i].Y;
        ll v2 = f2[i].X;
        ll pos1 = f1[0].Y;
        ll v1 = f1[0].X;
        if (min(pos1, pos2) + v1 + v2 <= n) {
            cout << "Yes" << endl;
            cout << v1 << " " << v2 << endl;
            if (pos1 < pos2) {
                for (int i = pos1; i < pos1 + v1; i++)
                    cout << a[i].Y << " ";
            } else {
                for (int i = max(pos1,pos2+v2); i < max(pos1,pos2+v2)+v1; i++)
                    cout << a[i].Y << " ";
            }
            cout << endl;

            if (pos2 <= pos1) {
                for (int i = pos2; i < pos2 + v2; i++)
                    cout << a[i].Y << " ";
            } else {
                for (int i = max(pos2,pos1+v1); i < max(pos2,pos1+v1)+v2; i++)
                    cout << a[i].Y << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}