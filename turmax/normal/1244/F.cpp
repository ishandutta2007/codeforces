#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int to(int a,int b)
{
    return min(abs(a-b),min(abs(b+n-a),abs(a+n-b)));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <pair<int,int> > a;
    vector <int> b(n);
    int sum1=0;
    int sum2=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='W')
        {
            b[i]=0;
            ++sum1;
        }
        else
        {
            b[i]=1;
            ++sum2;
        }
    }
    int curr,left;
    curr=b[0];
    left=0;
    for(int i=1;i<n;++i)
    {
        if(i==(n-1) || b[i]!=b[i-1])
        {
            if((i-left)!=1 || (i==(n-1) && left!=i && b[i]==b[i-1]))
            {
                if(i==(n-1) && b[i]==b[i-1])
                {
                    a.push_back({left,i});
                }
                else
                {
                a.push_back({left,i-1});
                }
            }
            left=i;
        }
        curr=b[i];
    }
    pair <int,int> u;
    if(sum1==n)
    {
        for(int i=0;i<n;++i)
        {
            cout<<"W";
        }
        return 0;
    }
    if(sum2==n)
    {
        for(int i=0;i<n;++i)
        {
            cout<<"B";
        }
        return 0;
    }
    if(b[n-1]==b[0])
    {
        if(a.size()==0)
        {
            a.push_back({n-1,0});
        }
        else if(a.size()>=1 && a[a.size()-1].second==(n-1) && a[0].first==0)
        {
            u.first=a[a.size()-1].first;
            u.second=a[0].second;
            a.erase(a.begin());
            a.erase(a.begin()+a.size()-1);
            a.push_back(u);
        }
        else if(a[a.size()-1].second==(n-1))
        {
            a[a.size()-1].second=0;
        }
        else if(a[0].first==0)
        {
            a[0].first==(n-1);
        }
        else 
        {
            a.push_back({n-1,0});
        }
    }
    if(a.size()==0)
    {
        if(k%2==0)
        {
            cout<<s;
            return 0;
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                if(s[i]=='W')
                {
                    cout<<"B";
                }
                else
                {
                    cout<<"W";
                }
            }
            return 0;
        }
    }
    sort(a.begin(),a.end());
    /*for(int i=0;i<a.size();++i)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }*/
    vector <int> ans(n);
    int t;
    int pl1;
    int x1,x2;
    for(int i=0;i<n;++i)
    {
        t=i;
        pl1=lower_bound(a.begin(),a.end(),make_pair(t,(long long) (-1)))-a.begin();
        if(pl1!=a.size())
        {
            x2=a[pl1].first;
        }
        else
        {
            x2=a[0].first;
        }
        if(pl1!=0)
        {
            x1=a[pl1-1].second;
        }
        else
        {
            x1=a[a.size()-1].second;
        }
        // cout<<i<<" "<<x1<<" "<<x2<<endl;
        if(min(to(i,x1),to(i,x2))<=k)
        {
            if(to(i,x1)<to(i,x2))
            {
                ans[i]=b[x1];
                continue;
            }
            else
            {
                ans[i]=b[x2];
                continue;
            }
        }
        else
        {
            ans[i]=(b[i]+k)%2;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(ans[i]==0)
        {
            cout<<"W";
        }
        else
        {
            cout<<"B";
        }
    }
    return 0;
}