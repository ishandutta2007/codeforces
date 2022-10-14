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
ll n,p,a[1000],i,x,rez;
string s; 

int main()
{
    cin >> p >> n;
    rez = n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (a[x%p]) rez = min(rez,i);
        a[x%p] = 1;
    }
    if (rez == n) cout << -1 << endl;
    else cout << rez+1 << endl;
    return 0;
}