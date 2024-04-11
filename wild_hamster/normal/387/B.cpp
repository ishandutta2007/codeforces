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
ll n,i,j,d,m,x,y,p,k,max1,a[105000],b[5000],e,l,rez,rows,cols;
string s1,s2,s;
int main()
{
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (j = 0; j < m; j++)
        cin >> b[j];
    ll pointer = n-1;
    for (i = m-1; i >= 0; i--)
    if (pointer >= 0)
        if (b[i] >= a[pointer]) pointer--;
           else pointer--,rez++,i++;
    cout << rez+pointer+1 << endl;
    return 0;
}