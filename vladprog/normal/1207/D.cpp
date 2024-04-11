#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100,MOD=998244353;

int fact[N];
pii srt[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%MOD;
    map<int,int> a,b;
    map<pii,int> ab;
    for(int i=1;i<=n;i++)
    {
        cin>>srt[i].x>>srt[i].y;
        a[srt[i].x]++;
        b[srt[i].y]++;
        ab[srt[i]]++;
    }
    int cnta=1;
    for(auto p:a)
        cnta=cnta*fact[p.y]%MOD;
    int cntb=1;
    for(auto p:b)
        cntb=cntb*fact[p.y]%MOD;
    int cntab=1;
    for(auto p:ab)
        cntab=cntab*fact[p.y]%MOD;
    sort(srt+1,srt+n+1);
    for(int i=1;i<n;i++)
        if(srt[i].y>srt[i+1].y)
            cntab=0;
    int ans=fact[n]-cnta-cntb+cntab;
    ans+=MOD*4;
    ans%=MOD;
    cout<<ans;

}