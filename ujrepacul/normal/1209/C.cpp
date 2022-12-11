#include <bits/stdc++.h>
using namespace std;
char v[200005];
int st1[200005],st2[200005],rz[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    long long n,i,j,m,k=0,x=0,t,s=0;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>v;
        int k1=0,k2=0;
        for(i=0;i<n;++i)
        {
            while(k1 && v[i]<v[st1[k1]])
                st2[++k2]=st1[k1--];
            st1[++k1]=i;
        }
        sort(st2+1,st2+k2+1);
        int ok=0;
        for(i=2;i<=k2;++i)
            if(v[st2[i]]<v[st2[i-1]])
            {
                cout<<"-\n";
                ok=1;
                break;
            }
        if(ok)
            continue;
        if(k2==0)
        {
            for(i=1;i<=n;++i)
                cout<<1;
            cout<<'\n';
            continue;
        }
        ok=0;
        int k1v=k1;
        for(i=1;i<=k1v;++i)
            if(v[st1[i]]>=v[st2[k2]] && st1[i]>st2[k2])
            {
                st2[++k2]=st1[i];
                if(ok==0)
                    k1=i-1;
                ok=1;
            }
        if(v[st1[k1]]>v[st2[1]])
        {
            cout<<"-\n";
            continue;
        }
        for(i=0;i<n;++i)
            rz[i]=1;
        for(i=1;i<=k2;++i)
            rz[st2[i]]=2;
        for(i=0;i<n;++i)
            cout<<rz[i];
        cout<<'\n';
    }
    return 0;
}