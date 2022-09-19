#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n;
    int a[n];
    int b[n];
    char s;
    string l;
    cin>>l;
    for(int i=0;i<n;++i)
    {
        s=l[i];
        if(s=='1')
        {
            a[i]=1;
        }
        else
        {
            a[i]=0;
        }
    }
    cin>>l;
    int sum=0;
    for(int i=0;i<n;++i)
    {
        s=l[i];
        if(s=='1')
        {
            b[i]=1;
        }
        else
        {
            b[i]=0;
        }
        sum+=b[i];
    }
    int c[n];
    int v=sum;
    for(int i=0;i<n;++i)
    {
        c[i]=a[i]+b[i];
    }
    int x=(n/2);
    bool used[n];
    for(int i=0;i<n;++i)
    {
        used[i]=false;
    }
    int h,h1,h2;
    vector <int> res;
    if(v==0)
    {
        int y=0;
        for(int i=0;i<n && y<(n/2);++i)
        {
            if(a[i]==0)
            {
                res.push_back(i+1);
                ++y;
            }
        }
        if(y<(n/2))
        {
            cout<<(-1);
            return 0;
        }
    }
    while(v>0)
    {
        if(v>x)
        {
            h=0;
            for(int i=0;i<n;++i)
            {
                if(used[i]==false && c[i]==2)
                {
                    res.push_back(i+1);
                    used[i]=true;
                    h=1;
                    x--;
                    v-=2;
                    break;
                }
            }
            if(h==0)
            {
                cout<<(-1);
                return 0;
            }
        }
        else if(v<x)
        {
            h=0;
            for(int i=0;i<n;++i)
            {
                if(used[i]==false && c[i]==0)
                {
                    res.push_back(i+1);
                    used[i]=true;
                    h=1;
                    x--;
                    break;
                }
            }
            if(h==0)
            {
                cout<<(-1);
                return 0;
            }
        }
        else if(v==x)
        {
             h=0;
             h1=0;
             h2=0;
             for(int i=0;i<n;++i)
             {
                if(used[i]==false && c[i]==1)
                {
                    res.push_back(i+1);
                    used[i]=true;
                    h=1;
                    x--;
                    v--;
                    break;
                }
             }
             if(h==0)
             {
                 for(int i=0;i<n;++i)
                 {
                    if(used[i]==false && c[i]==0)
                    {
                        res.push_back(i+1);
                        used[i]=true;
                        h1=1;
                        x--;
                        break;
                    }
                 }
                 for(int i=0;i<n;++i)
                 {
                    if(used[i]==false && c[i]==2)
                    {
                        res.push_back(i+1);
                        used[i]=true;
                        h2=1;
                        x--;
                        v-=2;
                        break;
                    }
                 }
                 if(h1==0 || h2==0)
                 {
                     cout<<(-1);
                     return 0;
                 }
             }
        }
        if(x<0)
        {
            cout<<(-1);
            return 0;
        }
    }
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}