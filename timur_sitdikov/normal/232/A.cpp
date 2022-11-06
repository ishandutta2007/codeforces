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

const int maxn=105, sz=100;
int g[maxn][maxn];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, i, j, k, ans, tmp, lim=100, tt;
    //for(n=1; n<=lim; n++)
    cin >> n;
    {
        ans=0;
        for(i=1; i<=sz; i++)
            for(j=1; j<+sz; j++)
                g[i][j]=0;
        for(i=0; ;i++)
        {
            ans=i*(i-1)*(i-2)/6;
            if (ans>n)
                break;
        }
        i--;
        ans=i*(i-1)*(i-2)/6;
        k=i;
        for(i=1; i<=k; i++)
            for(j=i+1; j<=k; j++)
                g[i][j]=g[j][i]=1;
        for(i=k+1; ; i++)
        {
            tmp=0;
            for(j=1; j<i; j++)
            {
                tmp=j*(j-1)/2;
                if (ans+tmp>n)
                    break;
            }
            j--;
            tmp=j*(j-1)/2;          
            for(;j>0; j--)
                g[i][j]=g[j][i]=1;
            ans+=tmp;
            if (ans==n)
                break;
        }
        /*tt=0;
        for(i=1; i<=sz; i++)
            for(j=i+1; j<=sz; j++)
                for(k=j+1; k<=sz; k++)
                    if (g[i][j] && g[j][k] && g[i][k])
                        tt++;
        if (tt!=n)
            cout << "p\n";*/
        cout << 100 << endl;
        for(i=1; i<=sz; i++)
        {
            for(j=1; j<=sz; j++)
                cout << g[i][j];
            cout << endl;
        }
    }
}