#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int h=1;
void go(int ans)
{
    cout<<(h*ans)%p;
    exit(0);
}
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    else
    {
        int u=po(a,b-1);
        return (a*u)%p;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x;
    cin>>n>>x;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    sort(a.begin(),a.begin()+n);
    for(int i=0;i<(n-1);++i)
    {
        h*=po(x,a[i]);
        h%=p;
    }
    int ans=1;
    while(true)
    {
        //cout<<a.size()<<endl;
        int n=a.size();
        int sum=0;
        int u=a[n-1];
        if(u==0)
        {
            go(ans);
        }
        for(int i=(n-1);i>=0;i--)
        {
            if(a[i]==a[n-1])
            {
                ++sum;
            }
            else
            {
                for(int j=0;j<sum;++j)
                {
                    a.erase(a.begin()+a.size()-1);
                }
                if(sum%x==0)
                {
                    for(int j=0;j<sum/x;++j)
                    {
                        a.push_back(u-1);
                    }
                }
                else
                {
                    go(ans);
                    return 0;
                }
                ans*=x;
                ans%=p;
                sum=0;
                break;
            }
            if(i==0)
            {
                for(int j=0;j<sum;++j)
                {
                    a.erase(a.begin()+a.size()-1);
                }
                if(sum%x==0)
                {
                    for(int j=0;j<sum/x;++j)
                    {
                        a.push_back(u-1);
                    }
                }
                else
                {
                    go(ans);
                    return 0;
                }
                ans*=x;
                ans%=p;
                sum=0;
                break;
            }
        }
    }
    return 0;
}