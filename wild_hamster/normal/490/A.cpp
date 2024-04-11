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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,s,rez,a[100500];
vector <ll> f[5];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        f[x].push_back(i+1);
    }
    ll siz = min(f[1].size(),min(f[2].size(),f[3].size()));
    cout << siz << endl;
    for (i = 0; i < siz; i++)
        cout << f[1][i] << " " << f[2][i] << " " << f[3][i] << endl;
    return 0;
}