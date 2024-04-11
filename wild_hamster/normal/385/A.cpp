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
ll n,i,j,d,m,x,r,y,p,k,max1,e,l,rez,a[100500];
string s1,s2,s;

int main()
{
    rez = 0;
    cin >> n >> x;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 1; i < n; i++)
        rez = max(rez,a[i-1]-a[i]-x);
    cout << rez << endl;
    return 0;
}