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
ll n,m,k,j,p,pN,pM,k1,k2,i,x;

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (x == 100) k1++;
        else k2++;
    }
    if ((k1 > 0 && k1%2 == 0)||(k1 == 0 && k2%2 == 0))
    cout << "YES" << endl;
    else
    cout << "NO" << endl;
    return 0;
}