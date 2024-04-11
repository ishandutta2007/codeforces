#include <bits/stdc++.h>
using namespace std;
int rz[100005];
int st[100005];
int v[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int s=0,n,i,t,j,k=0;
    cin>>n;
    for(i=1;i<=2*n;++i)
    {
        char c;
        cin>>c;
        if(c=='+')
            v[i]=-1;
        else
            cin>>v[i];
    }
    j=0;
    for(i=2*n;i>=1;--i)
    {
        if(v[i]==-1)
        {
            if(k==0)
            {
                cout<<"NO\n";
                return 0;
            }
            rz[++j]=st[k];
            --k;
        }
        else
        {
            if(k>0 && st[k]<v[i])
            {
                cout<<"NO\n";
                return 0;
            }
            st[++k]=v[i];
        }
    }
    cout<<"YES\n";
    for(i=n;i>=1;--i)
        cout<<rz[i]<<' ';
    return 0;
}