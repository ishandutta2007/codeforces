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
ll n,i,j,dp[5],min_sh[1005],a[2005],rez;
string s1,s2;
char c;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> c;
        a[i] = min_sh[i] = c-'0';
    }
    for (i = 0; i < n; i++)
    {
        ll tmp = 10 - a[i];
        for (j = i; j < i+n; j++)
        {
            a[j] = (a[j]+tmp)%10;
            //cout << a[j];
        }
        //cout << endl;
        ll flag = 1;
        for (j = i; j < i+n; j++)
            if (a[j] > min_sh[j-i])
            {
                     flag = 0;
                     break;
            } else
            if (a[j] < min_sh[j-i])
               break;
        if (flag)
        for (j = i; j < i+n; j++)
            min_sh[j-i] = a[j];
        a[n+i] = a[i];
    }
    for (i = 0; i < n; i++)
        cout << min_sh[i];
    cout << endl;
    return 0;
}