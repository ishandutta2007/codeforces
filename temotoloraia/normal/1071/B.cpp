#include <bits/stdc++.h>#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;
const int N = 2e3 + 5;

int n, k;
char a[N][N];
int b[N][N];
string S;
int F[N][N];

int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            char ch = getchar();
            while (ch < 'a' || 'z' < ch)
                ch = getchar();
            a[i][j] = ch;
        }
    b[1][1] = k - 1;
    if (a[1][1] == 'a')
        b[1][1]++;
    if (b[1][1] >= 0)
        a[1][1] = 'a';
    F[1][1] = 1;
    for (int L = 3; L <= n * 2; L++)
        for (int i = 1; i <= n; i++){
            int j = L - i;
            if (j < 1 || n < j)
                continue;
            b[i][j] = - N * N - 50;
            if (i > 1)
                b[i][j] = max (b[i][j], b[i - 1][j] - 1);
            if (j > 1)
                b[i][j] = max (b[i][j], b[i][j - 1] - 1);
            if (a[i][j] == 'a')
                b[i][j]++;
            if (b[i][j] >= 0)
                a[i][j] = 'a';
        }
    S = a[1][1];
    for (int L = 3; L <= n * 2; L++){
        int x = 25;
        for (int i = 1; i <= n; i++){
            int j = L - i;
            if (j < 1 || n < j)
                continue;
            if (F[i - 1][j] + F[i][j - 1] == 0)
                continue;
            x = min (x, a[i][j] - 'a');
        }
        char ch = x + 'a';
        S += ch;
        for (int i = 1; i <= n; i++){
            int j = L - i;
            if (j < 1 || n < j)
                continue;
            if (F[i - 1][j] + F[i][j - 1] == 0)
                continue;
            if (ch == a[i][j])
                F[i][j] = 1;
        }
    }
    cout<<S<<endl;
    return 0;
}