#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=105;
int a[maxn][maxn];
vector<vector<pair<int,int> > > res;
void f(vector <pair<int,int> > v)
{
    for(auto h:v)
    {
        a[h.first][h.second]^=1;
    }
    res.push_back(v);
}
void go(int i,int j)
{
    int sum=a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1];
    if(sum==4)
    {
        f({{i,j+1},{i+1,j},{i+1,j+1}});
        f({{i,j},{i+1,j},{i,j+1}});
        f({{i,j},{i+1,j},{i+1,j+1}});
        f({{i,j+1},{i,j},{i+1,j+1}});
        return;
    }
    else if(sum==3)
    {
        vector <pair<int,int> > v;
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(a[k][l]) v.push_back({k,l});
            }
        }
        f(v);
    }
    else if(sum==2)
    {
        vector <pair<int,int> > v;
        bool h=false;
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(!a[k][l]) v.push_back({k,l});
                else if(!h) {v.push_back({k,l});h=true;}
            }
        }
        f(v);
        v.clear();
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(a[k][l]) v.push_back({k,l});
            }
        }
        f(v);
    }
    else if(sum==1)
    {
        vector <pair<int,int> > v;
        int c0=0;
        int c1=0;
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(a[k][l] && c1==0) {v.push_back({k,l});c1++;}
                else if(c0<=1) {v.push_back({k,l});c0++;}
            }
        }
        f(v);
        v.clear();
        bool h=false;
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(!a[k][l]) v.push_back({k,l});
                else if(!h) {v.push_back({k,l});h=true;}
            }
        }
        f(v);
        v.clear();
        for(int k=i;k<(i+2);++k)
        {
            for(int l=j;l<(j+2);++l)
            {
                if(a[k][l]) v.push_back({k,l});
            }
        }
        f(v);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        res.clear();
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            for(int j=0;j<m;++j)
            {
                a[i][j]=s[j]-'0';
            }
        }
        if(n%2==0 && m%2==0)
        {
            for(int i=0;i<n;i+=2)
            {
                for(int j=0;j<m;j+=2)
                {
                    go(i,j);
                }
            }
        }
        else if(n%2==1 && m%2==0)
        {
            for(int j=0;j<m;++j)
            {
                if(a[0][j])
                {
                    if(j!=0)
                    {
                        f({{0,j},{1,j},{1,j-1}});
                    }
                    else
                    {
                        f({{0,j},{1,j},{1,j+1}});
                    }
                }
            }
            for(int i=1;i<n;i+=2)
            {
                for(int j=0;j<m;j+=2)
                {
                    go(i,j);
                }
            }
        }
        else if(n%2==0 && m%2==1)
        {
            for(int j=0;j<n;++j)
            {
                if(a[j][0])
                {
                    if(j!=0)
                    {
                        f({{j,0},{j,1},{j-1,1}});
                    }
                    else
                    {
                        f({{j,0},{j,1},{j+1,1}});
                    }
                }
            }
            for(int i=0;i<n;i+=2)
            {
                for(int j=1;j<m;j+=2)
                {
                    go(i,j);
                }
            }
        }
        else if(n%2==1 && m%2==1)
        {
            for(int j=0;j<m;++j)
            {
                if(a[0][j])
                {
                    if(j!=0)
                    {
                        f({{0,j},{1,j},{1,j-1}});
                    }
                    else
                    {
                        f({{0,j},{1,j},{1,j+1}});
                    }
                }
            }
            for(int j=1;j<n;++j)
            {
                if(a[j][0])
                {
                    if(j!=1)
                    {
                        f({{j,0},{j,1},{j-1,1}});
                    }
                    else
                    {
                        f({{j,0},{j,1},{j+1,1}});
                    }
                }
            }
            for(int i=1;i<n;i+=2)
            {
                for(int j=1;j<m;j+=2)
                {
                    go(i,j);
                }
            }
        }
        cout<<res.size()<<endl;
        for(auto z:res)
        {
            for(auto h:z)
            {
                 cout<<h.first+1<<' '<<h.second+1<<' ';
            }
            cout<<endl;
        }
    }
    return 0;
}