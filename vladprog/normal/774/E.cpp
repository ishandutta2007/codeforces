#pragma GCC optimize("O3")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N=2e5+100;
int pref[N],suff[N],pw[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int m;
    cin>>s>>m;
    int n=s.size();
    pw[0]=1;
    for(int i=1;i<=n;i++)
        pw[i]=pw[i-1]*10%m;
    pref[0]=(s[0]-'0')%m;
    for(int i=1;i<n;i++)
        pref[i]=(pref[i-1]*10+s[i]-'0')%m;
    suff[n]=0;
    for(int i=n-1;i>=0;i--)
        suff[i]=(suff[i+1]+(s[i]-'0')*pw[n-1-i])%m;
//    for(int i=0;i<=n;i++)
//    {
//        cout<<i<<" ->\t"<<pw[i]<<"\t"<<pref[i]<<"\t"<<suff[i];
//        if(i>=1&&i<n)
//            cout<<"\t"<<(suff[i]*pw[i]+pref[i-1])%m;
//        cout<<"\n";
//    }
    int ans=suff[0];
    for(int i=1;i<n;i++)
        if(s[i]!='0')
            ans=min(ans,(suff[i]*pw[i]+pref[i-1])%m);
    cout<<ans;
}