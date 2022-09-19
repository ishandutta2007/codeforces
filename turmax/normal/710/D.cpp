#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a1,b1,a2,b2,l,r;
    cin>>a1>>b1>>a2>>b2>>l>>r;
    if(a2>=a1)
    {
        swap(a1,a2);swap(b1,b2);
    }
    if(a1>=1000)
    {
        int ans=0;
        for(int i1=0;i1*a1+b1<=((int) 2e9);++i1)
        {
            int c=(i1*a1+b1);
            if(c>=l && c<=r && (c%a2+a2)%a2==(b2%a2+a2)%a2 && c>=b2)
            {
                ++ans;
            }
        }
        cout<<ans;
        return 0;
    }
    int ans=0;
    for(int i=0;i<a1*a2;++i)
    {
        if(i%a1==(b1%a1+a1)%a1 && i%a2==(b2%a2+a2)%a2)
        {
            //cout<<i<<" i "<<endl;
            int l1=max(max(l,b1),b2);
            //cout<<l1<<" l1 "<<endl;
            //cout<<r<<" r "<<endl;
            int r1=r;
            l1+=(a1*a2)*(((int) 1e18)/(a1*a2));
            r1+=(a1*a2)*(((int) 1e18)/(a1*a2));
            ans+=max(0LL,-max(0LL,((l1-1-i)/(a1*a2)))+max(0LL,((r1-i)/(a1*a2))));
        }
    }
    cout<<ans;
    return 0;
}