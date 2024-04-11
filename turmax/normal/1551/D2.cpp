#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > v;
void go(vector <vector <int> > v,int n,int m)
{
    char ans[n][m];
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) ans[i][j]='a';
    for(auto h:v)
    {
        int x=h[0];int y=h[1];
        assert(x>=0 && x<n && y>=0 && y<m);
        ans[x][y]=(7*x+y)%26+'a';
        int typ=h[2];
        if(typ==1)
        {
            assert((y+1)<m);
            ans[x][y+1]=ans[x][y];
        }
        else
        {
            assert((x+1)<n);
            ans[x+1][y]=ans[x][y];
        }
    }
    for(int i=0;i<n;++i) {for(int j=0;j<m;++j) cout<<ans[i][j]; cout<<'\n';}
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        v.clear();
        bool ok=0;
        if(n%2==0 && m%2==0)
        {
            if(k%2==0 && k>=0 && k<=(n*m)/2) {ok=1;cout<<"YES";}
            else cout<<"NO";
            cout<<'\n';
            if(ok)
            {
                for(int i=0;i<(n/2);++i)
                {
                    for(int j=0;j<(m/2);++j)
                    {
                        if((i*(m/2)+j)<k/2)
                        {
                            v.push_back({2*i,2*j,1});v.push_back({2*i+1,2*j,1});
                        }
                        else
                        {
                            v.push_back({2*i,2*j,0});v.push_back({2*i,2*j+1,0});
                        }
                    }
                }
            }
            if(ok) go(v,n,m);
            continue;
        }
        if(n%2==1 && m%2==1)
        {
             cout<<"NO"<<'\n';
             continue;
        }
        if(n%2==0 && m%2==1)
        {
            if(k%2==0 && k>=0 && k<=(n*m-n)/2) {ok=1;cout<<"YES";}
            else cout<<"NO";
            cout<<'\n';
            if(ok)
            {
                int j=(m-1);
                for(int i=0;i<(n/2);++i)
                {
                    v.push_back({2*i,j,0});
                }
                for(int i=0;i<(n/2);++i)
                {
                    for(int j=0;j<(m/2);++j)
                    {
                        if((i*(m/2)+j)<k/2)
                        {
                            v.push_back({2*i,2*j,1});v.push_back({2*i+1,2*j,1});
                        }
                        else
                        {
                            v.push_back({2*i,2*j,0});v.push_back({2*i,2*j+1,0});
                        }
                    }
                }
            }
            if(ok) go(v,n,m);
            continue;
        }
        if(n%2==1 && m%2==0)
        {
            if(k%2==(n*m/2)%2 && k>=(m/2) && k<=(n*m)/2) {ok=1;cout<<"YES";}
            else cout<<"NO";
            cout<<'\n';
            if(ok)
            {
                int i=(n-1);
                for(int j=0;j<(m/2);++j)
                {
                    v.push_back({i,2*j,1});
                    k--;
                }
                for(int i=0;i<(n/2);++i)
                {
                    for(int j=0;j<(m/2);++j)
                    {
                        if((i*(m/2)+j)<k/2)
                        {
                            v.push_back({2*i,2*j,1});v.push_back({2*i+1,2*j,1});
                        }
                        else
                        {
                            v.push_back({2*i,2*j,0});v.push_back({2*i,2*j+1,0});
                        }
                    }
                }
            }
            if(ok) go(v,n,m);
            continue;
        }
    }
    return 0;
}