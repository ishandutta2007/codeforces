#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define pque priority_queue
#define endl '\n'
#define For(i, a, b) for (int i = a; i < b; i++)
#define ForE(i, a, b) for (int i = a; i <= b; i++)
#define Ford(i, a, b) for (int i = a; i > b; i--)
#define FordE(i, a, b) for (int i = a; i >= b; i--)
#define PrintV(x) for (int i = 0; i < x.size(); i++) cout << x[i] << ' ';
#define PrintVl(x) for (int i = 0; i < x.size(); i++) cout << x[i] << endl;
#define Ptest(a) return cout << a << endl, 0;
typedef vector <int> vi;
typedef pair <int, int> ii;
typedef vector <vi > vvi;
typedef vector <ii > vii;

const int N = 2e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n, k, mnlev = N, ans;
int a[N], hgt[N], pre[N];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(a, 0, sizeof(a));
	memset(hgt, 0, sizeof(hgt));
	memset(pre, 0, sizeof(pre));
	cin >> n >> k;
    if (n == 1){
        cout << 0;
        return 0;
    }
    For(i, 0, n){
        cin >> a[i];
        mnlev = min(mnlev, a[i]);
    }
	sort(a, a + n);
	int idx = n - 1;
    for (int i = N - 2; i >= 0; i--){
        hgt[i] = hgt[i + 1];
        while (a[idx] == i && idx >= 0){
            hgt[i]++;
            idx--;
        }
    }
    for (int i = N - 2; i >= 0; i--){
        pre[i] = pre[i + 1] + hgt[i];
    }
    if (pre[mnlev + 1] == 0){
        cout << 0;
        return 0;
    }
    int tcost, temp = N - 1;
    while (temp > mnlev){
        tcost = k;
        while (hgt[temp] <= tcost && temp >= mnlev){
            tcost -= hgt[temp];
            temp--;
        }
        ans++;
    }
    cout << ans;
}

/*
----------------------------------+
INPUT:  						  |
==============================    |
5 5
3 1 2 2 4
==============================    |
4 5
2 3 4 5
==============================    |
----------------------------------+
OUTPUT: 						  |
==============================    |
2
==============================    |
2
==============================    |
----------------------------------+
*/