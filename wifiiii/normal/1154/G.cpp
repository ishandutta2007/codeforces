
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
#include <unordered_map>
using namespace std;
typedef long long ll;

const int maxn = 1e7+5;
struct min2
{
    ll a,b;
    int posa,posb;
    void insert(ll x,int posx)
    {
        if(x<a) swap(a,x),swap(posa,posx);
        if(x<b) swap(b,x),swap(posx,posb);
    }
}M;
int a[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll ans = 1e18;
    int posx, posy;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        if(a[tmp] && ans > tmp)
        {
            ans = tmp;
            posx = a[tmp];
            posy = i;
        }
        a[tmp] = i;
    }
    for(int i=1;i<=1e7;++i)
    {
        M.a = M.b = 1e18;
        for(int j=i;j<=1e7;j+=i)
        {
            if(a[j]) M.insert(j, a[j]);
        }
        if(M.b < 1e18)
        {
            if(M.a*M.b/i < ans)
            {
                ans = M.a*M.b/i;
                posx = M.posa;
                posy = M.posb;
            }
        }
    }
    if(posx > posy) swap(posx, posy);
    cout << posx << " " << posy << endl;
}