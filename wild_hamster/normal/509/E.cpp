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
ll n,i,j,d,x,y,m,len,r,sum,a[500005],part[500005];
double moredroby[500005],droby[500005],partdroby[500005];
string s;
long double rez;
int main()
{
    cin >> s;
    n = s.size();
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'A'||s[i] == 'O'||s[i] == 'E'||s[i] == 'U'||s[i] == 'Y'||s[i] == 'I')
           a[i+1] = 1;
        sum += a[i+1];
    }
    part[1] = 0;
    for (i = 1; i <= n; i++)
        part[i+1] = part[i] + a[i];
    for (i = 1; i <= n; i++)
        droby[i] = 1./i;
    partdroby[1] = 0;
    for (i = 1; i <= n; i++)
        partdroby[i+1] = partdroby[i]+droby[i];
    for (i = 1; i <= n/2; i++)
    {
        moredroby[i] = moredroby[i-1] + (double)i/(n-i+1);
    }
    //for (i = 1; i <= n/2; i++)
      //  cout << moredroby[i] << " ";
    for (i = 1; i <= n; i++)
    {
        if (i > n/2)
           j = n-i+1;
        else
            j = i;
        if (a[i])
           rez += (partdroby[n-j+2]-partdroby[j])*j+j-1+moredroby[j-1];
        //cout << (partdroby[n-j+2]-partdroby[j])*j+moredroby[j-1] << endl;
    }
    cout.precision(20);
    cout << rez << endl;
    cout.setf( ios::fixed, ios::floatfield );
    return 0;
}