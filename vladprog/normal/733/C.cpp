#include<bits/stdc++.h>

using namespace std;

const int N=500;

int a[N],l[N],r[N];

void pl(int x)
{
    x++;
    cout<<x<<" L\n";
}

void pr(int x)
{
    x++;
    cout<<x<<" R\n";
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;
    int j=0;
    for(int i=0;i<k;i++)
    {
        int b;
        cin>>b;
        int s=0;
        l[i]=j;
        for(;s<b&&j<n;j++)
            s+=a[j];
        if(s!=b)
            cout<<"NO",exit(0);
        r[i]=j-1;
        set<int>ss;
        for(int t=l[i];t<=r[i];t++)
            ss.insert(a[t]);
        if(r[i]!=l[i]&&ss.size()==1)
            cout<<"NO",exit(0);
    }
    if(j==n)
        cout<<"YES\n";
    else
        cout<<"NO\n",exit(0);
    for(int i=0;i<k;i++)
    {
        if(l[i]==r[i])
            continue;
        //cout<<i+1<<": l="<<l[i]<<" r="<<r[i]<<"\n";
        int j,m=0;
        for(j=l[i];j<=r[i];j++)
            m=max(m,a[j]);
        bool c=false;
        for(j=l[i];j<=r[i]-1;j++)
            if(a[j]==m&&a[j+1]!=m)
            {
                c=true;
                break;
            }
        if(c) /// RIGHT
        {
            //cout<<"j="<<j<<" ";
            j-=l[i];
            //cout<<"j="<<j<<" ";
            pr(j+i);
            r[i]--;
        }
        else /// LEFT
        {
            for(j=l[i]+1;j<=r[i];j++)
                if(a[j]==m&&a[j-1]!=m)
                    break;
            //cout<<"j="<<j<<" ";
            j-=l[i];
            //cout<<"j="<<j<<" ";
            pl(j+i);
            j--;
            r[i]--;
        }
        r[i]-=l[i];
        while(j>0)
            pl(j+i),j--,r[i]--;
        while(j<r[i])
            pr(j+i),r[i]--;
    }
}