#include <bits/stdc++.h>
using namespace std;
int v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,m,k,i,j,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0,n;
    cin>>n;
    int mx=0;
    for(i=1;i<=n;++i)
    {
        // incerc cu i
        for(j=1;j<=n;++j)
            v[j]=0;
        int cnt=0;
        int s=0;
        for(j=1;j<n;++j)
        {
            v[j]=1;
            ++cnt;
            if(cnt==i+1)
            {
                cnt=0;
                v[j]=0;
            }
            s+=v[j];
        }
        mx=max(mx,s-i);
    }
    for(i=1;i<=n;++i)
    {
        // incerc cu i
        for(j=1;j<=n;++j)
            v[j]=0;
        int cnt=0;
        int s=0;
        for(j=1;j<n;++j)
        {
            v[j]=1;
            ++cnt;
            if(cnt==i+1)
            {
                cnt=0;
                v[j]=0;
            }
            s+=v[j];
        }
        if(s-i==mx)
            break;
    }
    int val=i+1;
    if(mx==0)
    {
        cout<<0<<'\n';
        cout.flush();
    }
    for(t=1;t<=mx;++t)
    {
        int cnt=0;
        for(i=1;i<=n;++i)
            if(v[i]==1)
                ++cnt;
        if(cnt<val)
        {
            cout<<cnt<<' ';
            for(i=1;i<=n;++i)
                if(v[i]==1)
                    cout<<i<<' ';
            cout<<'\n';
            cout.flush();
            int a;
            cin>>a;
            cout<<0<<'\n';
            cout.flush();
            return 0;
        }
        cout<<val<<' ';
        int vlc=val;
        for(i=1;i<=n && vlc;++i)
        {
            if(v[i]==1 && vlc)
            {
                cout<<i<<' ';
                v[i]=2;
                --vlc;
            }
        }
        cout<<'\n';
        cout.flush();
        int pz;
        cin>>pz;
        vlc=val;
        for(i=pz;vlc;++i)
        {
            if(i==n+1)
                i=1;
            v[i]=min(v[i],1);
            --vlc;
        }
    }
    cout<<0<<'\n';
    cout.flush();
    return 0;
}