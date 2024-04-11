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
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,l,r,z;
string s1,s2,s3,s,t;
ll a[100500];
int main()
{
    int a,b;
    cin >> a >> b;
    if (a < b)
    {
        cout << -1 << endl;
        return 0;
    }
    ll y1 = (b-a)/(2LL*b);
    ll y2 = (a+b)/(2LL*b);
    if (y1 != 0)
    printf("%.10f\n",min((double)(b-a)/(double)(2.*y1),(double)(b+a)/(double)(2.*y2)));
    else
    printf("%.10f\n",(double)(b+a)/(double)(2.*y2));
    return 0;
}