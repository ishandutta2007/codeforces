#include<iostream>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
using namespace std;
struct point
{
    int first, second;
    int idx;
    bool operator < (point const & p) const
    {
        if(first==p.first) return second<p.second;
        return first<p.first;
    }
};
typedef pair<int,int> pii;
typedef long long ll;
const int mod = 1e9+7;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    char op;
    int a=0, b=0;
    while(n--)
    {
        cin >> op;
        if(op=='+')
        {
            int x,y;
            cin>>x>>y;
            if(y<x) swap(x,y);
            a = max(a,x);
            b = max(b,y);
        }
        if(op=='?')
        {
            int x,y;
            cin>>x>>y;
            if(y<x) swap(x,y);
            if(a<=x&&b<=y) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
}