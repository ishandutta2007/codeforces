#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#define tr 1000000007
#define mp make_pair
typedef long long ll;
using namespace std;
ll k,j,x,y,n,m,cnt,i,sixs[10],b[30];
string s;

int main()
{
   // cout << x10(1000000006) << endl;
   k = 0;cnt = 0;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 1 && k == 0) cnt += 2;
        else if (x == 1 && k == 1) cnt++;
        k = x;    
    }
    if (cnt == 0)
    cout << cnt << endl;
    else
    cout << cnt - 1 << endl;
    return 0;
}