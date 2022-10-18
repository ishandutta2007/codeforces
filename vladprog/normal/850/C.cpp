#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;
const ld one=1;

typedef pair<int,int> pii;
#define x first
#define y second

unordered_map<int,int> mem;

int solve(int mask)
{
    if(mem.count(mask))
        return mem[mask];
    unordered_set<int> s;
    for(int i=0;;i++)
    {
        int ones=(1ll<<i)-1;
        int low=mask&ones;
        int high=(mask|ones)^ones;
        if(!high)
            break;
        s.insert(solve(low|(high>>(i+1))));
    }
    for(int i=0;;i++)
        if(!s.count(i))
            return //cout<<mask<<" -> "<<i<<"\n",
                   mem[mask]=i;
}

const int N=110;
map<int,int> fact[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    set<int> pr;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int p=2;p*p<=x;p++)
            while(x%p==0)
                x/=p,
                fact[i][p]++,
                pr.insert(p);
        if(x>1)
            fact[i][x]++,
            pr.insert(x);
    }
    unordered_set<int> s;
    int ans=0;
    for(int p:pr)
    {
        int mask=0;
        for(int i=1;i<=n;i++)
            if(fact[i].count(p))
                mask|=1ll<<(fact[i][p]-1);
        ans^=solve(mask);
    }
    cout<<(ans?"Mojtaba":"Arpa");
}