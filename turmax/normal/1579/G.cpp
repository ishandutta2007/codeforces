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
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int low=(-1);int up=2005;
        while(true)
        {
            if((up-low)==1)
            {
                cout<<up<<'\n';
                break;
            }
            int mid=(low+up)/2;
            bool ok[mid+1];
            for(int i=0;i<=mid;++i) ok[i]=true;
            bool ok1[mid+1];
            for(int i=0;i<n;++i)
            {
                int val=a[i];
                for(int j=0;j<=mid;++j) ok1[j]=false;
                for(int j=0;j<=mid;++j)
                {
                    if((j+val)<=mid)
                    {
                        ok1[j+val] |= ok[j];
                    }
                    if(j>=val)
                    {
                        ok1[j-val] |= ok[j];
                    }
                }
                for(int j=0;j<=mid;++j) ok[j]=ok1[j];
            }
            bool ok0=false;
            for(int i=0;i<=mid;++i) ok0=(ok0 || ok[i]);
            if(ok0) up=mid;
            else low=mid;
        }
    }
    return 0;
}