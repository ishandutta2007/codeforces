#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[1000500];
string s;
ll Abs(ll x)
{
    return x>0?x:-x;
}
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        a[x] = i;
    }
    for (i = 2; i <= n; i++)
        p += Abs(a[i] - a[i-1]);
    cout << p << endl;
    return 0;
}