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
string s1, s2, s3;
int main()
{
    cin >> s1;
    if (s1[0] != '-')
       cout << s1 << endl;
    else
    {
        n = s1.size();
        if (n == 3&&s1[2] == '0')
        {
              cout << 0 << endl;
              return 0;
        }
        for (i = 0; i < s1.size()-2; i++)
            cout << s1[i];
        cout << min(s1[n-1],s1[n-2]);
    }
    return 0;
}