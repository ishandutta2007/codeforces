#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
typedef long long ll;
using namespace std;
ll i,j,n,l,r,rez,k,m,y,z,x,a[100];
string s;

int main()
{
    cin >> l >> r;
    if (r - l > 2 || (r-l>=2&&l%2 == 0))
    {
       l = ((l+1)/2)*2;
       cout << l << " " << l+1 << " " << l+2 << endl;
    }
    else
        cout << -1 << endl;   
    return 0;
}