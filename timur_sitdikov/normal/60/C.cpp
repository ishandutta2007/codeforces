#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx first
#define yy second

const int maxn=105;

long long gcd[maxn][maxn], lcm[maxn][maxn], v[maxn];
int n, st[maxn], col[maxn];

long long my_gcd(long long a, long long b)
{
    return b? my_gcd(b, a%b): a;
}

int dfs(int s)
{
    int i;
    col[s]=1;
    for(i=1; i<=n; i++)
        if (lcm[s][i])
        {
            if ((lcm[s][i]%v[s]) || (v[s]%gcd[s][i]))
                return 0;
        }
    for(i=1; i<=n; i++)
        if (lcm[s][i] && !col[i])
        {
            v[i]=lcm[s][i]/v[s]*gcd[s][i];
            if (!dfs(i))
                return 0;
        }
    for(i=1; i<=n; i++)
        if (lcm[s][i])
        {
            if ((lcm[s][i]%v[s]) || (v[s]%gcd[s][i]) ||
                (v[s]*v[i]!=gcd[s][i]*lcm[s][i]) || my_gcd(v[s], v[i])!=gcd[s][i])
                return 0;
        }
    return 1;
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int m, a, b, i, j, k;
    long long c, d, lim;
    cin >> n >> m;
    for(i=0; i<m; i++)
    {
        cin >> a >> b >> c >> d;
        gcd[a][b]=gcd[b][a]=c;
        lcm[a][b]=lcm[b][a]=d;
        st[a]++;
        st[b]++;
    }
    for(i=1; i<=n; i++)
    {
        if (st[i]==0)
        {
            v[i]=1;
            continue;
        }
        if (col[i])
            continue;
        for(j=1; j<=n; j++)
            if (lcm[i][j])
                break;
        lim=lcm[i][j];
        for(j=1; j*j<=lim; j++)
            if (!(lim%j))
            {
                v[i]=j;
                for(k=1; k<=n; k++)
                    col[k]=0;
                if (dfs(i))
                    break;
                v[i]=lim/j;
                for(k=1; k<=n; k++)
                    col[k]=0;
                if (dfs(i))
                    break;
            }
        if (j*j>lim)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    for(i=1; i<=n; i++)
        cout << v[i] << " ";
}