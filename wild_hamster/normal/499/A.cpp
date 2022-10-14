#include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
#define tr 1000000007
typedef long long ll;
using namespace std;
ll x1,y1,x2,y2,x,y,n,m,q,i,j,k,k1,k2,l,a[100500],mt[50000],used[50000];
ll rez;
set <ll> f;
set<ll>::iterator itr;
vector <ll> new_graph[3500];
vector <pair<ll,ll> > queries;
vector <ll> new_vertices[105];
ll gcd(ll a, ll b)
{
          if (a%b == 0) return b;
          return gcd(b,a%b);
}
int main()
{
    cin >> n >> m;
    l = 1;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        while (l + m <= x)
              l += m;
        rez += y - l + 1;
        l = y + 1;
    }
    cout << rez << endl;
    return 0;
}