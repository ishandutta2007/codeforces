#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int x[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,r,ans=0;
        cin>>n>>r;
        for(int i=0;i<n;i++)
            cin>>x[i];

        sort(x,x+n);
        x[n]=inf;

        for(int i=n-1;i>=0;i--)
        {
            if(x[i]<=r*ans)break;
            if(x[i]==x[i+1])continue;

            ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}