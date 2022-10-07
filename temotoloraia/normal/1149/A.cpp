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

const int N = 1e6 + 5;

int n, a, b;

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x == 1)
            a++;
        else
            b++;
    }
    if (a == 0 || b == 0){
        int x = 1;
        if (a == 0)
            x = 2;
        for (int i = 0; i < n; i++)
            cout << x << " ";
        cout << endl;
        return 0;
    }
    cout << 2 << " " << 1 << " ";
    for (int i = 1; i < b; i++)
        cout << 2 << " ";
    for (int i = 1; i < a; i++)
        cout << 1 << " ";
    cout << endl;
    return 0;
}