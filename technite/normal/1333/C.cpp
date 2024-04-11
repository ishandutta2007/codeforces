#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long> v(n);
    map<long long,int> m;
    for(int i=0;i<n;i++) cin>>v[i];
    vector<long long> prefix(n+1);
    prefix[0]=0;
    m[0]=0;
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+v[i-1];
    }
    int t=-1;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        long long sum=prefix[i];
        if(m.find(sum)==m.end())
        {
            ans+=i-t-1;
        }
        else
        {
            t=max(t,m[sum]);
            ans+=i-t-1;
            
        }
        m[sum]=i;   
        
    }
    cout<<ans<<'\n';
    
}