#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=4e5+5;
vector<int> di[maxn];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<maxn;++i) for(int j=i;j<maxn;j+=i) di[j].push_back(i);
    int t;cin>>t;
    while(t--)
    {
        int ans=0;
        int l,r;cin>>l>>r;
        for(int i=l+2;i<=r;++i)
        {
            vector<int> v=di[i];
            vector<int> v1;for(int x:v) if(x>=l && x<i) v1.push_back(x);
            ans+=v1.size()*(((int) v1.size())-1)/2;
            if((2*i)%3==0 && (i%2==0) && (2*i/3>=l) && (2*i/4>=l)) ++ans;
            if((2*i)%3==0 && (((2*i)%5)==0) && (2*i/3>=l) && (2*i/5>=l)) ++ans;
        }
        cout<<(r-l+1)*(r-l)*(r-l-1)/6-ans<<'\n';
    }
    return 0;
}