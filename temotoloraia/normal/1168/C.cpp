#include <bits/stdc++.h>
//#pragma GCC diagnostic warning "-std=c++11"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
using namespace std;

const int N = 300005, M = 800;


int n, Q;
int B[30];
int a[N];
int mas[30];
int A[N][30];

int main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    B[0] = 1;
    for (int i = 1; i <= 30; i++)
        B[i] = B[i - 1] * 2;
    cin >> n >> Q;
    for (int i = 1; i <= n; i++){
        scanf ("%d", &a[i]);
        for (int j = 0; j < 20; j++)
            if ((a[i] & B[j]) > 0)
                for (int t = 0; t < 20; t++)
                    if ((a[mas[j]] & B[t]) > 0)
                        A[i][t] = max (A[i][t], mas[j]);
        for (int j = 0; j < 20; j++)
            for (int t = 0; t < 20; t++)
                A[i][t] = max (A[i][t], A[A[i][j]][t]);
        for (int j = 0; j < 20; j++)
            if ((a[i] & B[j]) > 0)
                mas[j] = i;
        for (int j = 0; j < 20; j++)
            if ((a[i] & B[j]) > 0)
                A[i][j] = i;
    }
    while (Q--){
        int l, r;
        scanf ("%d %d", &l, &r);
        string ans = "Fou";
        for (int i = 0; i < 20; i++)
            if ((a[l] & B[i]) > 0)
                if (A[r][i] >= l)
                    ans = "Shi";
        cout << ans << endl;
    }
    return 0;
}