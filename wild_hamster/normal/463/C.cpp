#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
typedef long long ll;
using namespace std;
    ll n,a[2005][2005],i,j,k,x1,x2,y1,y2,rez1,rez2,b[5000],c[5000];
int main()
{
    rez1 = -1; rez2 = -1;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
    {
        scanf("%d",&k);
        a[i][j] = k;
        b[i+j] += k;
        c[i-j+2000] += k;
    }
    for (i = 0; i < n; i++)
        for (j = i%2; j < n; j+=2)
            if (rez1 < b[i+j]+c[i-j+2000]-a[i][j])
            {
             rez1 = b[i+j]+c[i-j+2000]-a[i][j];
             x1 = i+1; x2 = j+1;
            }
    rez2 = rez1;
    rez1 = -1;
    for (i = 0; i < n; i++)
        for (j = (i+1)%2; j < n; j+=2)
            if (rez1 < b[i+j]+c[i-j+2000]-a[i][j])
            {
             rez1 = b[i+j]+c[i-j+2000]-a[i][j];
             y1 = i+1; y2 = j+1;
            }
    cout << rez1 + rez2 << endl << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
    return 0;
}