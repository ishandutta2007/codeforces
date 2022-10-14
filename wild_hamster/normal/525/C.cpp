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
ll x,y,w,l,r,i,j,n,t,k,k1,k2,d,m,q,dr,a[100505],b[100505],c[100050];
string s;
vector <ll> f;
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a,a+n);
    reverse(a,a+n); 
    i = 0;   
    while (i < n - 1)
    {
     if (a[i] == a[i+1] || a[i] - 1 == a[i+1])
     {
      f.push_back(a[i+1]);
      i += 2;
     } else
     i++;
    }
    
    k = f.size();
    k /= 2;
    k *= 2;
    ll rez = 0;
    for (i = 0; i < k/2; i++)
        rez += f[i*2]*f[i*2+1];
    cout << rez << endl;
    return 0;
}