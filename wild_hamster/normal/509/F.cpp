#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,i,j,d,x,y,m,len,l,r,sum,a[105005],e[1000][1000];
string s;
long double rez;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        e[i][i] = e[i][i+1] = 1;
    for (j = 2; j <= n-1; j++)
        for (i = 1; i <= n-j; i++)
        {
            l = i;
            r = i+j;
            e[l][r] = e[l+1][r];
            for (int pos = l+1; pos < r; pos++)
            {
                //cout << pos << endl;
                e[l][r] += e[l+1][pos]*e[pos][r]*(a[l+1]<a[pos+1]);
                e[l][r] %= MOD;
            }
        }
    /*for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout << e[i][j] << " ";
        cout << endl;
    }*/
    cout << e[1][n] << endl;
    return 0;
}