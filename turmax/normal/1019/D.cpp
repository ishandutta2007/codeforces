#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e3+5;
pair <int,int> a[maxn];
const int p=71;
vector <int> b[p][p][p];
int s;
bool check(pair <int,int> a,pair <int,int> b,pair <int,int> c)
{
    int s1=a.first*b.second+b.first*c.second+c.first*a.second-a.second*b.first-b.second*c.first-c.second*a.first;
    s1=abs(s1);
    if(2*s==s1)
    {
        cout<<"Yes"<<endl;
        cout<<a.first<<' '<<a.second<<endl;
        cout<<b.first<<' '<<b.second<<endl;
        cout<<c.first<<' '<<c.second<<endl;
        exit(0);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>s;
    for(int i=0;i<n;++i) cin>>a[i].first>>a[i].second;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<p;++j)
        {
            for(int k=0;k<p;++k)
            {
                b[j][k][((j*a[i].first+k*a[i].second)%p+p)%p].push_back(i);
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            // x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3
            int x1=a[i].first;int y1=a[i].second;
            int x2=a[j].first;int y2=a[j].second;
            int w=(2*s-x1*y2+x2*y1);
            int u=(y1-y2);
            int v=(x2-x1);
            u%=p;u+=p;u%=p;
            v%=p;v+=p;v%=p;
            w%=p;w+=p;w%=p;
            for(auto h:b[u][v][w])
            {
                int s1=x1*y2+x2*a[h].second+a[h].first*y1-y1*x2-y2*a[h].first-a[h].second*x1;
                s1=abs(s1);
                if(2*s==s1)
                {
                cout<<"Yes"<<endl;
                cout<<x1<<' '<<y1<<endl;
                cout<<x2<<' '<<y2<<endl;
                cout<<a[h].first<<' '<<a[h].second<<endl;
                exit(0);
                }
            }
            for(auto h:b[u][v][(p-w)%p])
            {
                int s1=x1*y2+x2*a[h].second+a[h].first*y1-y1*x2-y2*a[h].first-a[h].second*x1;
                s1=abs(s1);
                if(2*s==s1)
                {
                cout<<"Yes"<<endl;
                cout<<x1<<' '<<y1<<endl;
                cout<<x2<<' '<<y2<<endl;
                cout<<a[h].first<<' '<<a[h].second<<endl;
                exit(0);
                }
            }
        }
    }
    cout<<"No";
    return 0;
}