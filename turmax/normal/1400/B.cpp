#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int a1,a2;
    cin>>a1>>a2;
    int c1,c2;
    cin>>c1>>c2;
    int w1,w2;
    cin>>w1>>w2;
    if(w1>=w2)
    {
        swap(w1,w2);swap(c1,c2);
    }
    if((a1/w1+a2/w1)<=(c1))
    {
        cout<<(a1/w1+a2/w1)<<endl;
        continue;
    }
    int ans=0;
    for(int i=0;i<=c1;++i)
    {
        if((i*w1)>a1) continue;
        if((c1-i)*w1>a2) continue;
        ans=max(ans,c1+(a1-w1*i)/w2+(a2-w1*(c1-i))/w2);
    }
    ans=min(ans,c1+c2);
    cout<<ans<<endl;
    }
    return 0;
}