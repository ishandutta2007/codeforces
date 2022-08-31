#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int N = 111;
int n;
string s[N];
int a[N];
int cnt;
int ans;
bool u[(int)1e6 + 10];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i] >> a[i];
        if (s[i] == "-" && !u[a[i]])
            cnt++;
        u[a[i]] = 1;
    }
    ans = cnt;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == "-")
            cnt--;
        else
            cnt++;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

    return 0;
}