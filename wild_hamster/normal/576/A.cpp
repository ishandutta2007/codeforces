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
ll i,j,n,k,k1,k2,k3,m,x,y,l,r,z;
string s1,s2,s3,s,t;
ll a[100500],primes[100500];
vector<ll> f;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 2; i <= 100000; i++)
        primes[i] = 1;
    for (i = 2; i <= 100000; i++)
    if (primes[i])
       for (j = i*i; j <= 100000; j+=i)
           primes[j] = 0;

    for (i = 2; i <= n; i++)
        if (primes[i])
        {
            for (j = i; j <= n; j *= i)
                f.push_back(j);
        }
    cout << f.size() << endl;
    for (i = 0; i < f.size(); i++)
        cout << f[i] << " ";
    return 0;
}