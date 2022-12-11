#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int N = 1e6 + 7, INF = 1e18;
int a[N];
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
        while (j <= n && cnt < k) {
            if (a[j] == 1) {
                right += j - i;
                cnt++;
                cr++;
            }
            j++;
        }
        j--;
        for (int t = i; t <= j; t++) {
            mini = min(mini, left + right);
            if (a[t] == 1) {
                cl++;
                cr--;
            }
            left += cl;
            right -= cr;
        }
        ans += mini;
        i = j;
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
        cin >> a[i];
        if (a[i] == 1) k++;
    }
    if (k == 1) {
        cout << -1 << endl;
        return 0;
    }
    fact(k);
    int mini = INF;
    for (int elem : pr) mini = min(mini, check(n, elem));
    cout << mini << endl;
}