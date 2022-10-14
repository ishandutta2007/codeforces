#include <iostream>
//#include <cmath>
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
ll n,i,j,k1,k2,x,k,y,m,l,r,c,t,a[200005],sum;
int main()
{
    for (i = 0; i < 8; i++)
        cin >> a[i];
    cout << min((a[1]*a[2])/a[6],min(a[3]*a[4],a[5]/a[7]))/a[0] << endl;
    return 0;
}