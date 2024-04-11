#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
typedef int ll;
#define mp make_pair
#define MOD 1000000007
ll n,m,k,n1,n2,i,j, x,y,l,r, coord,p,q;
ll a[1000500], b[1000500], pb[1000500];
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> p >> q;
    cin >> s;
    for (i = 0; i <= 105; i++)
        for (j = 0; j <= 105; j++)
            if (i*p + j*q == n)
            {
                cout << i+j << endl;
                for (k = 0; k < i*p; k+=p)
                    cout << s.substr(k,p) << endl;
                for (k = i*p; k < n; k+=q)
                    cout << s.substr(k,q) << endl;
                return 0;
            }
    cout << -1 << endl;
    return 0;
}