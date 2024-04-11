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
ll x,y,l,r,i,j,n,k,k1,k2,d,m,a[100500],b[100500],q,dr;

ll rez;
char c;
int main()
{
    cin >> n >> m;
    rez = 0;
    while (n != 0 && m != 0 && (n != 1 || m != 1))
    {
     if (m >= n)
     {
           m -= 2;
           n--;
     } else
     {
           n -= 2;
           m--;
     }
     rez++;
    }
    cout << rez << endl;
    return 0;
}