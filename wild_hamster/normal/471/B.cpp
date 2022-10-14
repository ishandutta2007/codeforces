 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll rez,l,r,n,m,k,j,p,k1,k2,i;
pair <ll,ll> a[100000];
vector <ll> rezs[2005];
ll Abs(ll x)
{
 if (x < 0) return -x;
    return x;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a,a+n);
    rez = 1;
    for (i = 0; i < n; i++)
        rezs[i].push_back(a[i].second);
    for (i = 1; i < n; i++)
    if (rez < 3)
    {
        if (a[i].first == a[i-1].first)
        {
         rez++;
         swap(a[i],a[i-1]);
         for (j = 0; j < n; j++)
             rezs[j].push_back(a[j].second);
        }           
    }
    if (rez < 3) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < n; j++)
                cout << rezs[j][i] << " ";
            cout << endl;
        }
    }
    return 0;
}