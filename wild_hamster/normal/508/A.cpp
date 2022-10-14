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
ll n,i,j,d,x,k,y,m,l,r,sum,a[1005][1005],rez;
int main()
{
    cin >> n >> m >> k;
    for (i = 0; i < k; i++)
    {
        cin >> x >> y;
        if ((a[x-1][y] == 1&&a[x-1][y-1] == 1&& a[x][y-1] == 1)||
        (a[x+1][y] == 1&&a[x+1][y+1] == 1&& a[x][y+1] == 1)||
        (a[x+1][y] == 1&&a[x+1][y-1] == 1&& a[x][y-1] == 1)||
        (a[x-1][y] == 1&&a[x-1][y+1] == 1&& a[x][y+1] == 1))
        {
         cout << i+1 << endl;
         return 0;
        }
        a[x][y] = 1;
    }
    cout << 0 << endl;
    return 0;
}