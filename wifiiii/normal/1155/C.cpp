
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <deque>
using namespace std;

typedef  long long  ll;
const int maxn = 3e5+10;
ll x[maxn], p[maxn];

ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>x[i];
    for(int i=2;i<=n;++i) x[i]-=x[1];
    for(int i=1;i<=m;++i) cin>>p[i];
    ll g = x[2];
    for(int i=2;i<=n;++i) g=gcd(g,x[i]);
    for(int i=1;i<=m;++i)
    {
        if(g%p[i]==0)
        {
            cout << "YES" << endl;
            cout << x[1] << " " << i << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}