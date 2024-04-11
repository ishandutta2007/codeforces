#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9;
int k;
string s;
int n;

int solve(int w)
{
    int ans = 0;
    int l = 0;
    while(l < n)
    {
        ans++;
        int r = l + w;
        if (r >= n) break;
        while(r > l && s[r - 1] != ' ' && s[r - 1] != '-') r--;
        if (r == l) return INF;
        l = r;
    }
    return ans;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    cin >> k;
    getline(cin, s);
    getline(cin, s);

    n = s.length();
    int l = 0, r = n;
    while(r - l > 1)
    {
        int m = (l + r) / 2;
        if (solve(m) <= k)
            r = m;
        else
            l = m;
    }
    cout << r << endl;

    return 0;
}