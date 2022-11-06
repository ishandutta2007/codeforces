#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

#define maxn 200010

int n, s;
int v[maxn];
int f[maxn];
int nxt[maxn];

int getNxt(int cpoz, int spec)
{
    int ans=nxt[cpoz];
    if(spec<=cpoz && spec>ans)
        ans=spec;
    return ans;
}

int solve(int val)
{
    int csum=s;
    int prv=s+1;
    while(csum>0)
    {
        int cr=getNxt(min(csum, prv-1), val);
        if(cr==0 || cr==prv)
            return 1;
        prv=cr;
        if(1LL*csum>1LL*f[cr]*cr)
            csum-=f[cr]*cr;
        else
            csum%=cr;
    }
    return 0;
}

int main()
{
    cin>>s;
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        ++f[x];
    }

    for(int i=1; i<=s; ++i)
    {
        if(f[i]==0)
            nxt[i]=nxt[i-1];
        else
            nxt[i]=i;
    }

    int sol=0;
    for(int cval=1; cval<s; ++cval)
    {
        ++f[cval];
        if(solve(cval))
        {
            sol=cval;
            break;
        }
        --f[cval];
    }
    if(!sol)
        cout<<"Greed is good\n";
    else
        cout<<sol<<"\n";

    return 0;
}