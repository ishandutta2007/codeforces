#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
char c;

void solve()
{
    cin >> s >> c;
    int n = s.size();
    bool ok = false;
    rep(i, n) if(i % 2 == 0 && s[i] == c) ok = true;
    cout << (ok ? "YES" : "NO") << "\n";
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}