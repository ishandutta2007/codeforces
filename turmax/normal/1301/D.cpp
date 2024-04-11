#include <bits/stdc++.h>

using namespace std;
#define int long long
int k;
vector <pair<int,string> > a;
void go(int x,string s)
{
    a.push_back({x,s});
}
void go(int n,int m)
{
    //cout<<n<<" "<<m<<" "<<k<<endl;
    if(k==0)
    {
        return;
    }
    if(m==1)
    {
        if(k<n)
        {
            go(k,"R");
            k=0;
        }
        else if(k<(2*n-1))
        {
            go(n-1,"R");
            k-=(n-1);
            go(k,"L");
            k=0;
        }
        else
        {
            go(n-1,"R");
            k-=(n-1);
            go(n-1,"L");
            k-=(n-1);
        }
        return;
    }
    if(k<=(n-1))
    {
        go(k,"R");
        k=0;
        return;
    }
    go(n-1,"R");
    k-=(n-1);
    if(k<(3*(n-1)))
    {
        if(k>=3)
        go(k/3,"DUL");
        k%=3;
        if(k>0)
        {
            go(1,"D");
            k--;
        }
        if(k>0)
        {
            go(1,"U");
            k--;
        }
        if(k>0)
        {
            go(1,"L");
            k--;
        }
        return;
    }
    else
    {
        go(n-1,"DUL");
        k-=3*(n-1);
        if(k==0)
        {
            return;
        }
        go(1,"D");
        k--;
        go(n,m-1);
        if(k>0)
        {
            go(1,"U");
            k--;
        }
        return;
    }

}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m>>k;
    if(k>(4*m*n-2*n-2*m))
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        cout<<"YES"<<endl;
    }
    go(m,n);
    for(int i=a.size()-1;i>=0;--i)
    {
        if(a[i].first==0)
        {
            a.erase(a.begin()+i);
        }
    }
    cout<<a.size()<<endl;
    for(int i=0;i<a.size();++i)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }
    return 0;
}