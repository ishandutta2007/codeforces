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
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
        cin >> a[i];
    ll ans = 0;
    ans = a[n-1];
    for (i = 0; i < n-k; i++)
        ans = max(ans, a[i] + a[2*n-2*k-i-1]); 
    cout << ans << endl;
    return 0;
}