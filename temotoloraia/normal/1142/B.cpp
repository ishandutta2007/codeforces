#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const ll N = 1e6 + 5;

int n, m, Q;
int p[N];
int w[N];
int a[N];
int A[N][20];
int mas[N];
int L[N][20], R[N][20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> Q;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 2; i <= n; i++)
        w[p[i]] = p[i - 1];
    w[p[1]] = p[n];
    for (int i = 1; i <= m; i++){
        cin >> a[i];
        A[i][0] = mas[w[a[i]]];
        mas[a[i]] = i;
    }
    for (int i = 1; i < 19; i++)
        for (int j = 1; j <= m; j++)
            A[j][i] = A[A[j][i - 1]][i - 1];
    for (int i = 1; i <= n; i++)
        mas[i] = 0;
    for (int i = 1; i <= m; i++){
        int t = 1;
        int ind = i;
        for (int I = 18; I >= 0; I--){
            if (A[ind][I] == 0)
                continue;
            if (t + (1 << I) > n)
                continue;
            t += (1 << I);
            ind = A[ind][I];
        }
        if (t == n)
            mas[i] = ind;
    }
    for (int i = 1; i <= m; i++){
        L[i][0] = mas[i];
        R[i][0] = mas[i];
    }
    for (int i = 1; i < 19; i++)
        for (int j = 1; j <= m; j++){
            L[j][i] = max (L[j][i - 1], L[j + (1 << (i - 1))][i - 1]);
            if (j >= (1 << (i - 1)))
                R[j][i] = max (R[j][i - 1], R[j - (1 << (i - 1))][i - 1]);
        }
    string s = "";
    while (Q--){
        int l, r;
        cin >> l >> r;
        string ans = "0";
        for (int I = 0; (1 << I) <= r - l + 1; I++)
            if (max (L[l][I], R[r][I]) >= l)
                ans = "1";
        s += ans;
    }
    cout << s << endl;
    return 0;
}