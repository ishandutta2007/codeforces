#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n],b[n],pos[n+1];for(int i=0;i<n;++i) {cin>>a[i];pos[a[i]]=i;} for(int i=0;i<n;++i) cin>>b[i];
        bool used[n+1]={0};
        int c=0,c1=0;
        for(int i=0;i<n;++i)
        {
            int x=a[i];
            if(used[x]) continue;
            int pos1=i;
            int sz=0;
            while(true)
            {
                used[x]=true;
                x=b[pos1];pos1=pos[x];++sz;
                if(x==a[i]) break;
            }
            if(sz%2==0) {c+=sz/2;}
            else {c+=(sz-1)/2;}
        }
        cout<<2*(n*(n+1)/2-(n-c)*(n-c+1)/2-c*(c+1)/2)<<'\n';
    }
    return 0;
}