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
ll j,x,y,n,m,cnt,i,sixs[10],b[30];
string s;

int main()
{
   // cout << x10(1000000006) << endl;
    cin >> n;
    cin >> s;
    i = 0;
    while (s[i] == '1' && i < n)
          i++;
    if (i == n) cout << n << endl;
       else
    cout << i+1 << endl;

    return 0;
}