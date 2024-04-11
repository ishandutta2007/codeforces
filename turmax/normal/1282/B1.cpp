#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    for(int cycle=0;cycle<q;++cycle)
    {
    int n,c,k;
    cin>>n>>c>>k;
    vector <int> a(n);
    vector <vector <int> > pr(k);
    vector <int> pr1(n+1);
    for(int i=0;i<k;++i)
    {
        pr[i].push_back(0);
    }
    pr1[0]=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int t;
    for(int i=0;i<n;++i)
    {
        t=pr[(i%k)][pr[(i%k)].size()-1];
        pr[(i%k)].push_back(t+a[i]);
        pr1[i+1]=pr1[i]+a[i];
    }
    /*for(int i=0;i<n;++i)
    {
        cout<<a[i]<<" ";
    }*/
    //cout<<endl;
    int ma=0;
    int z;
    int r;
    int h;
    for(int i=0;i<k;++i)
    {
        z=(i+2*k-1)%k;
        if(i==0)
        {
            r=0;
            h=0;
        }
        else
        {
            r=a[i-1];
            h=1;
        }
        //cout<<c-pr1[i]+r<<" tgrfdeswqa "<<endl;
        ma=max(ma,i+(upper_bound(pr[z].begin(),pr[z].end(),c-pr1[i]+r)-pr[z].begin()-1-h)*k);
        //cout<<ma<<endl;
    }
    cout<<ma<<endl;
    }
    return 0;
}