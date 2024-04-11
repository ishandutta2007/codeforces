#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e6+5;
bool used[maxn];
vector <int> pr;
void sieve()
{
    used[0]=true;
    used[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(!used[i])
        {
            pr.push_back(i);
            for(int j=2*i;j<maxn;j+=i)
            {
                used[j]=true;
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1) {cout<<1<<'\n';continue;}
        else
        {
            int x=sqrt(n);
            int ans=lower_bound(pr.begin(),pr.end(),n+1)-lower_bound(pr.begin(),pr.end(),x+1);
            cout<<ans+1<<'\n';
        }
    }
    return 0;
}