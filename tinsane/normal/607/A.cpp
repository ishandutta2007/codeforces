#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <unordered_map>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;

struct Node
{
    int x, r;
    Node() {}
    Node(int x) : x(x) {}
    void read()
    {
        cin >> x >> r;
    }
    bool operator< (const Node& n) const
    {
        return (x < n.x);
    }
};

const int N = 1e5 + 10;
int n, dp[N], ans;
Node mas[N];

void init()
{
    cin >> n;
    ans = n;
    for(int i(0); i < n; ++i)
        mas[i].read();
    sort(mas, mas + n);
}

void solve()
{
    dp[0] = 0;
    if (n == 1)
        ans = 0;
    for(int i(1); i < n; ++i)
    {
        Node* it = lower_bound(mas, mas + n, Node(mas[i].x - mas[i].r));
        int pos = (it - mas);
        dp[i] = i - pos;
        if (pos > 0)
            dp[i] += dp[pos - 1];
        ans = min(ans, dp[i] + n - i - 1);
    }
}

void output()
{
    cout << ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
 }