#include <omp.h>
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
typedef long long ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, op[1000500], md, a[100050];
ll x,y;
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    cin >> k >> n >> w;
    m = ((w*(w+1))/2)*k;
    if (m > n)
       cout << m-n << endl;
    else
        cout << 0 << endl;
    return 0;
}