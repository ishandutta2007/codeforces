#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
using namespace std;
int n,i,j,k, a[505], down[505][505], up[505][505],x,y;
string s;
int main() {
    cin >> n >> k;
    cin >> s;
    for (i = 0; i < n ; i++)
        a[s[i]-'a']++;
    int m = 0;
    for (i = 0; i < 26; i++)
        m = max(m, a[i]);
    cout << (m>k?"NO":"YES") << endl;
    return 0;
}