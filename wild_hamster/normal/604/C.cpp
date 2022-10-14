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
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    cin >> s;
    j = 0;
    for (i = 0; i < n; i++)
    {
        if (j == 0)
        {
            a[j++] = s[i];
        } else
        {
            if (s[i] != a[j-1])
                a[j++] = s[i];
        }
    }
    cout << min(n,j+2) << endl;
    return 0;
}