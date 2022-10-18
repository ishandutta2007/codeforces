#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=1e7+100;

int lp[N+1];
vector<int> pr;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int p,q;
    cin>>p>>q;
    int ans=0,pi=0,rub=0;
    lp[0]=lp[1]=1;
    rub++;
    if(pi*q<=p*rub)
        ans=1;
    for(int i=2;i<=N;i++)
    {
        if(lp[i]==0)
            lp[i]=i,pr.push_back(i),pi++;
        string s;
        int t=i;
        while(t)
            s.push_back('0'+t%10),t/=10;
        t=atoi(s.c_str());
        if(t==i)
            rub++;
        if(pi*q<=p*rub)
            ans=i;
        for(int p:pr)
        {
            if(p*i>N||p>lp[i])
                break;
            lp[p*i]=p;
        }
    }
    cout<<ans;
}