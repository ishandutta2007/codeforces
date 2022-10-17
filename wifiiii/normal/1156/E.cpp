
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 2e5+5;


int a[maxn], st[200005][20];
int query(int l,int r)
{
    int i = 1;
    while(l + (1<<i) <= r) i++;
    i--;
    if(a[st[l][i]] > a[st[r-(1<<i)+1][i]]) return st[l][i];
    else return st[r-(1<<i)+1][i];
    return 1;
}
int solve(int l,int r)
{
    if(r-l<2) return 0;
    int ret = 0;
    int Mi = query(l, r), Mx = a[Mi];
    if(Mi==r||Mi==l);
    else
    {
        set<int> s;
        if(r-Mi > Mi-l)
        {
            for(int i=Mi+1;i<=r;++i) s.insert(Mx-a[i]);
            for(int i=l;i<Mi;++i) if(s.find(a[i]) != s.end()) ret++;
        }
        else
        {
            for(int i=l;i<Mi;++i) s.insert(Mx-a[i]);
            for(int i=Mi+1;i<=r;++i) if(s.find(a[i]) != s.end()) ret++;
        }
    }
    ret += solve(l,Mi-1) + solve(Mi+1,r);
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i],st[i][0]=i;
    for(int i=1;1<<i <= n;++i)
    {
        for(int j=1;j+(1<<i)-1<=n;++j)
        {
            if(a[st[j][i-1]] > a[st[j+(1<<i-1)][i-1]]) st[j][i] = st[j][i-1];
            else st[j][i] = st[j+(1<<(i-1))][i-1];
        }
    }
    cout << solve(1,n) << endl;
}