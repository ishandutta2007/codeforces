#pragma GCC optimize("O3","Ofast","unroll-loops")
#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
bool used[maxn];
vector <int> pr;
vector <int> rasl(int x)
{
    vector <int> v;
    if(x==1) return v;
    for(int i=0;pr[i]*pr[i]<=x;++i)
    {
        int h=pr[i];
        if(x%h==0)
        {
            v=rasl(x/h);
            v.push_back(h);
            return v;
        }
    }
    v.push_back(x);
    return v;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used[0]=true;used[1]=true;
    for(int i=2;i<maxn;++i) for(int j=(2*i);j<maxn;j+=i) used[j]=true;
    for(int i=0;i<maxn;++i) if(!used[i]) pr.push_back(i);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,k;
        cin>>a>>b>>k;
        vector <int> v1=rasl(a);vector <int> v2=rasl(b);
        int o=__gcd(a,b);
        if(k==1)
        {
            if(a==b) cout<<"NO"<<endl;
            else if(a%b==0 || b%a==0) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            continue;
        }
        if(v1.size()+v2.size()<k)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        continue;
    }
    return 0;
}