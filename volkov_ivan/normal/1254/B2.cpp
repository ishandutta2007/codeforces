#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 1e6 + 7, INF = 1e18;
int a[N], b[N];
vector <int> pr;

void fact(int n) {
    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            pr.push_back(i);
            while (n % i == 0) n /= i;
        }
        i++;
    }
    if (n != 1) pr.push_back(n);
}

int check(int n, int k) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        int j = i;
        int mini = INF;
        int left = 0, right = 0, cl = 0, cr = 0;
        //cout << i << ' ' << a[i] << endl;
        while (j <= n && cnt < k) {
            int lst = min(a[j], k - cnt);
            right += (j - i) * lst;
            cr += lst;
            cnt += lst;
            /*if (a[j] == 1) {
                right += j - i;
                cnt++;
                cr++;
            }*/
            j++;
        }
        j--;
        if (cnt == 0) break;
        for (int t = i; t <= j; t++) {
            mini = min(mini, left + right);
            int lst = min(a[t], cr);
            if (t == j) {
                a[t] -= lst;
            }
            cr -= lst;
            cl += lst;
            left += cl;
            right -= cr;
        }
        ans += mini;
        i = j - 1;
    }
    return ans;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        k += b[i];
    }
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    fact(k);
    int mini = INF;
    for (int elem : pr) {
        for (int i = 1; i <= n; i++) a[i] = b[i] % elem;
        mini = min(mini, check(n, elem));
    }
    cout << mini << endl;
}