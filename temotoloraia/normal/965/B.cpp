#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long int
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
int n, k;
char ch[105][105];
int a[105][105];
int main()
{
    cin>>n>>k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin>>ch[i][j];
    for (int i = 1; i <= n - k + 1; i++)
        for (int j = 1; j <= n; j++){
            bool ok = 1;
            for (int l = i; l < i + k; l++)
                if (ch[l][j] == '#')
                    ok = 0;
            if (ok == 0)
                continue;
            for (int l = i; l < i + k; l++)
                a[l][j]++;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - k + 1; j++){
            bool ok = 1;
            for (int l = j; l < j + k; l++)
                if (ch[i][l] == '#')
                    ok = 0;
            if (ok == 0)
                continue;
            for (int l = j; l < j + k; l++)
                a[i][l]++;
        }
    int M = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i][j] > M)
                M = a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
    if (a[i][j] == M){
        cout<<i<<" "<<j<<endl;
        return 0;
    }
    return 0;
}