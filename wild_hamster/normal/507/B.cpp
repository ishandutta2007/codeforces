#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
using namespace std;
string s;
double q,n,i,j,k1,k2,k3,d,x,k,y,xx,yy,m,l,r,c,t,sum,a[100500];

int main()
{
    cin >> r >> x >> y >> xx >> yy;
    k = sqrt((xx-x)*(xx-x)+(yy-y)*(yy-y));
//    cout << k << endl;
    double rez = fmod(k,2*r);
    k = k-rez;
    ll tt = (k+0.1)/(2*r);
    if (rez > 0)
       tt++; 
    cout << tt << endl;
    return 0;
}