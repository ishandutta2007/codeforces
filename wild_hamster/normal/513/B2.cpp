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
ll n1,n2,k1,k2,n,i,j,d,x,y,m,len,l,r,sum,a[105005],b[105000];

int main()
{
    cin >> n >> m;
    m--;
    ll l = 0, r = n-1;
    for (i = n-2; i >= 0; i--)
        if ((m&(1LL<<i)) == 0)
        {
          a[l++] = n-i-1;
        }
        else
            a[r--] = n-i-1;
    a[l] = n;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;  
    return 0;
}