#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;

ll x1,x2,x3,n,i,j,k,x,y,m,k1,k2,k3,a[500];
string s[50];
ll Abs(ll a)
{
 if (a < 0) return -a;
 return a;
}
int main()
{
    cin >> n;
    for (i = 0; i < 2*n + 1; i++)
        for (j = 0; j < 2*n + 1; j++)
    {
        if (n-abs(n - i)-abs(n - j) < 0)
           s[i]. push_back(' ');
        else
            s[i].push_back(n-abs(n - i)-abs(n - j)+'0');
    }
    for (i = 0; i < 2*n + 1; i++)
    {
        j = 2*n;
        while (s[i][j] == ' ')
              s[i][j--] = 'A';
    }
    for (i = 0; i < 2*n+1; i++)
    {
        j = 0;
        while (j < 2*n && s[i][j+1] != 'A')
              cout << s[i][j++] << " ";
        cout << s[i][j] << endl;
    }
        
    return 0;
}