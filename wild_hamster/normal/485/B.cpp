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
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,a[204000],pos[1005000],used[1005000],rez;
vector <ll> f;

int main()
{
    ll maxy,miny;
    ll maxx = maxy = -(ll)1e+18, minx = miny = (ll)1e+18;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        maxx = max(maxx,x);
        maxy = max(maxy,y);
        minx = min(minx,x);
        miny = min(miny,y);
    }
    cout << max((maxx-minx),(maxy - miny))*max((maxx-minx),(maxy - miny)) << endl;
    //system("pause");
    return 0;
}