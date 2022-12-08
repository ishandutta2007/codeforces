

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;


const int maxn = 2750199;
int prime[maxn],np[maxn],tot=0,c[maxn],a[2*maxn],md[maxn];
void init()
{
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            md[i*prime[j]] = prime[j];
            if(i%prime[j]==0) break;
        }
    }
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) c[i]=prime[i];
        else c[i]=i/md[i];
    }
}

int cnt[2750199];
int main()
{
    init();
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,2*n)
    {
        int tmp;
        cin>>tmp;
        cnt[tmp]++;
    }
    vector<int> ans;
    for(int i=2750198;i>=1;--i)
    {
        while(cnt[i] && cnt[c[i]]) cnt[i]--,cnt[c[i]]--,ans.push_back(i);
    }
    for(int i:ans) cout<<i<<" ";
}