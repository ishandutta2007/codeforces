#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[4000500], back[4000050], t[4000050];
string s;
set <ll> f;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        for (j = 0; j < x; j++)
        {
            cin >> y;
            f.insert(y);
        }
    }
    if (f.size() == m)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}