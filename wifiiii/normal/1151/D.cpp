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

struct node
{
    ll a,b;
    bool operator < (const node & n) const
    {
        return a-b > n.a-n.b;
    }
}ns[100005];
int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>ns[i].a>>ns[i].b;
    sort(ns+1,ns+1+n);
    ll ans = 0;
    for(int i=1;i<=n;++i)
    {
        ans += ns[i].a*(i-1) + ns[i].b*(n-i);
    }
    cout << ans << endl;
}