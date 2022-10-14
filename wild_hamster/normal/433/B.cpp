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
ll l,r,n,m,k,j,p,pN,pM,k1,k2,i,x,a[100500],b[100500],parta[100500],partb[100500];

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        parta[i+1] = parta[i] + a[i];
        b[i] = a[i];
    }
    sort(b,b+n);
    for (i = 0; i < n; i++)
        partb[i+1] = partb[i] + b[i];
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> l >> r;
        if (x == 1) cout << parta[r] - parta[l-1] << endl;
        else cout << partb[r] - partb[l-1] << endl;
    }
    return 0;
}