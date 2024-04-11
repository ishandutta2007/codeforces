#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define For(i, a, b)  for(int i = a; i < b; ++i)
#define mp make_pair
#define x first
#define y second
#define point pair <int, int>
#define read(s1, s2); freopen(s1, "r", stdin); freopen(s2, "w", stdout);

using namespace std;

int n, k;
int arr[100001];
vector <int> ans[100001];
int cnt;

main() {
    cin >> n >> k;
    For(i, 0, k) {
        int s;
        cin >> s;
        For(j, 0, s) {
            int a;
            cin >> a;
            ans[i].push_back(n - a);
            arr[n - a] = i;
        }
    }
    For(i, 0, n) {
        if (ans[arr[i]].size() == n - i) {
            break;
        }
        //cout << cnt << endl;
        cnt += ans[arr[i]].size() != 1;
        ++cnt;
        //cout << cnt << endl;
        ans[arr[i]].pop_back();
    }
    cout << cnt;
}