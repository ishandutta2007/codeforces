#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
ll i,j,n,rez,a[100500],x,k;
int main()
{
    cin >> n >> x;
    rez = 0;
    for (i = 0; i < n; i++)
    {
        cin >> k;
        rez += k;
    }
    if (rez < 0) rez = -rez;
    if (rez == 0) cout << 0 << endl; else
    cout << (rez-1)/x+1 << endl;
    return 0;
}