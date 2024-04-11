#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define l1 l1228
#define l2 l2228
#define r1 r1228
#define r2 r2228
#define x1 x1228
#define y1 y1228
using namespace std;

vector < int > v;
const int A = 2e5, B = 7e5;

void solve (int n, int x){
    if (n == 0)
        return;
    if (n == 1){
        v.pb (x);
        return;
    }
    if (n == 2){
        v.pb (1);
        v.pb ((x ^ 1));
        return;
    }
    if (n == 4){
        if (x != 1){
            v.pb (A);
            v.pb (A + 1);
            v.pb (1);
            v.pb (x);
            return;
        }
        v.pb (A);
        v.pb (A + 2);
        v.pb (2);
        v.pb (x);
        return;
    }
    if (n % 2 == 1){
        int k = B;
        while (n > 2){
            v.pb (k);
            v.pb (k + 1);
            x ^= (k ^ (k + 1));
            n -= 2;
            k += 2;
        }
        v.pb (x);
        return;
    }
    int k = B;
    while (n > 4){
        v.pb (k);
        v.pb (k + 1);
        x ^= (k ^ (k + 1));
        n -= 2;
        k += 2;
    }
    solve (4, x);
}



int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    if (n == 2 && x == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    solve (n, x);
    for (int i = 0; i < (int)v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}