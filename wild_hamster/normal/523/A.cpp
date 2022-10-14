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
#define MOD 1000000009
typedef long long ll;
using namespace std;
ll x,y,w,l,r,i,j,n,k,k1,k2,d,m,q,max1,t,amnt,a[100500],b[100500];
char c[1005][1005];
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    cin >> n >> m;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            cin >> c[i][j];
    for (i = 0; i < m/2; i++)
        for (j = 0; j < n; j++)
            swap(c[i][j],c[m-i-1][j]);
    for (j = 0; j < n; j++)
    {
        for (i = m-1; i >= 0; i--)
            cout << c[i][j] << c[i][j];
        cout << endl;
        
        for (i = m-1; i >= 0; i--)
            cout << c[i][j] << c[i][j];
        cout << endl;
    }
    return 0;
}