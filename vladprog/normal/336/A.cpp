#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    cin>>x>>y;
    int s=abs(x)+abs(y);
    x=(x>0?1:-1)*s;
    y=(y>0?1:-1)*s;
    pair<int,int> p1(x,0),p2(0,y);
    if(p1>p2) swap(p1,p2);
    cout<<p1.first<<" "<<p1.second<<" "<<p2.first<<" "<<p2.second;
}