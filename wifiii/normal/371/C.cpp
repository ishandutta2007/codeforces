
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int main()
{
    string S;
    cin>>S;
    ll b=0,s=0,c=0;
    for(int i=0;i<S.size();++i)
    {
        if(S[i]=='B') b++;
        if(S[i]=='S') s++;
        if(S[i]=='C') c++;
    }
    ll nb,ns,nc,pb,ps,pc,r;
    cin>>nb>>ns>>nc>>pb>>ps>>pc>>r;
    ll lo=0,hi=1e14;
    while(lo<hi)
    {
        ll m=(lo+hi+1)/2;
        ll tot = 0;
        if(nb < b*m) tot += (b*m-nb)*pb;
        if(ns < s*m) tot += (s*m-ns)*ps;
        if(nc < c*m) tot += (c*m-nc)*pc;
        if(tot <= r) lo=m;
        else hi=m-1;
    }
    cout<<lo<<endl;
}