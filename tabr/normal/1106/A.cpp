#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define forx(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define caseout(i, X) cout << "Case #" << i << ": " << X << endl;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,ans=0;
    cin >> n;

    char c[n + 2][n + 2];

    rep(i, n){
        c[0][i] = '.';
        c[n + 1][i] = '.';
        c[i][0] = '.';
        c[i][n + 1] = '.';
    }

    rep(i, n) rep(j, n)cin >> c[i][j];

    rep(i,n)rep(j,n){
        if(c[i][j]=='X'){
        if (c[i-1][j-1] == 'X' && c[i+1][j-1] == 'X' && c[i-1][j+1] == 'X' && c[i+1][j+1] == 'X')
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}