#include <bits/stdc++.h>
//#pragma GCC diagnostic warning "-std=c++11"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

const int N = 300005, M = 800;

int n;
string s;

bitset < M + 5 > B1[N];
bitset < M + 5 > B2[N];
bitset < M + 5 > B;

ll mas[N];
ll ans;

void solve (){
    for (int i = 1; i <= n; i++){
        B1[i] = 0;
        B2[i] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= i - M && j >= 0; j--)
            if (s[i] == '1')
                B1[i][i - j] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= i + M && j <= n; j++)
            if (s[i] == '1')
                B2[i][j - i] = 1;
    for (ll i = 1; i <= n; i++){
        if (s[i] == '0')
            continue;
        int L = i, R = i;
        int pas = 0;
        while (1 <= L && R <= n){
            B = (B1[L] & B2[R]);
            if (B.any()){
                pas = L - 1;
                break;
            }
            L -= M;
            R -= M;
        }
        for (ll j = pas; j >= 1 && j > pas - M; j--)
        if (s[j] == '1' && s[i * 2 - j] == '1'){
            mas[j] = min (mas[j], i * 2 - j);
        }
    }
}

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> s;
    n = (int)s.size();
    s = "#" + s;
    for (int i = 1; i <= n; i++)
        mas[i] = n + 1;
    solve ();
    for (int i = 1; i <= n; i++)
        s[i] = '0' + '1' - s[i];
    solve ();
    for (int i = n - 1; i >= 1; i--)
        mas[i] = min (mas[i], mas[i + 1]);
    for (int i = 1; i <= n; i++)
        ans += n - mas[i] + 1;
    cout << ans << endl;
    return 0;
}