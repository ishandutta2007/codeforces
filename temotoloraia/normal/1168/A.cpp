#include <bits/stdc++.h>
//#pragma GCC diagnostic warning "-std=c++11"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

const int N = 300005, MOD = 1e9 + 5;

int n, m;
int a[N];
int b[N];

bool check (int t){
    for (int i = 1; i <= n; i++){
        if (a[i] + t < m){
            b[i] = max (a[i], b[i - 1]);
            //cout << i << "  " << a[i] << " " << b[i] << endl;
            if (b[i] > a[i] + t)
                return 0;
            continue;
        }
        if (a[i] <= b[i - 1]){
            b[i] = b[i - 1];
            continue;
        }
        if ((a[i] + t) % m >= b[i - 1]){
            b[i] = b[i - 1];
            continue;
        }
        b[i] = a[i];
    }
    /*if (t == 0)
        for (int i = 1; i <= n; i++)
        cout << a[i] << " " << b[i] << "\n";*/
    return 1;
}

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l = 0, r = m;
    while (r - l > 0){
        int mid = l + r >> 1;
        if (check (mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}