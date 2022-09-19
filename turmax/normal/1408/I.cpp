#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=998244353;
const int maxn=(1<<16)+5;
int cnt[maxn];
vector <vector <int> > dp;
int k;
int c;
int c1[20][20];
int maxbit(int x)
{
    for(int i=16;i>=0;i--)
    {
        if(x & (1<<i))
        {
            return i;
        }
    }
}
int po(int a,int b)
{
    if(b==0) return 1;
    if(b==1) return a;
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
int inv(int x)
{
    return po(x,p-2);
}
vector <vector <int> > build(vector <pair<int,pair<int,int> > > g)
{
    vector <vector <int> > answ(k+1);
    for(int i=0;i<=k;++i) {answ[i].resize(1<<c);for(int j=0;j<(1<<c);++j) answ[i][j]=0;}
    for(auto h:g)
    {
        answ[h.second.first][h.second.second]=h.first;
    }
    return answ;
}
vector <pair<int,pair<int,int> > > mul1(vector <pair<int,pair<int,int> > > a,vector <pair<int,pair<int,int> > > b)
{
    map <pair<int,int>,int> m;
    vector <pair<int,int> > keys;
    vector <pair<int,pair<int,int> > > ans;
    for(auto h1:a)
    {
        for(auto h2:b)
        {
            if((h1.second.first+h2.second.first)<=k)
            {
                pair <int,pair<int,int> > z={(h1.first*h2.first)%p*c1[h1.second.first+h2.second.first][h1.second.first],{h1.second.first+h2.second.first,h1.second.second^h2.second.second}};
                if(m.count(z.second))
                {
                    m[z.second]=(m[z.second]+z.first)%p;
                }
                else
                {
                    m[z.second]=(z.first%p);
                    keys.push_back(z.second);
                }
            }
        }
    }
    for(auto z:keys)
    {
        ans.push_back({m[z],z});
    }
    return ans;
}
vector <vector <int> > answ;
void mul(vector <vector <int> > &a,vector <vector <int> > b)
{
    vector <pair<int,int> > used1;
    vector <pair<int,int> > used2;
    for(int i=0;i<=k;++i)
    {
        for(int j=0;j<(1<<c);++j)
        {
            if(a[i][j]) used1.push_back({i,j});
            if(b[i][j]) used2.push_back({i,j});
        }
    }
    for(int i=0;i<=k;++i) for(int j=0;j<(1<<c);++j) answ[i][j]=0;
    for(auto h1:used1)
    {
        for(auto h2:used2)
        {
            if((h1.first+h2.first)<=k)
            {
                answ[h1.first+h2.first][h1.second^h2.second]+=((a[h1.first][h1.second]*b[h2.first][h2.second])%p)*c1[h1.first+h2.first][h1.first];
                answ[h1.first+h2.first][h1.second^h2.second]%=p;
            }
        }
    }
    a=answ;
}
vector <pair<int,pair<int,int> > > degree(vector <pair<int,pair<int,int> > > h,int x)
{
    if(x==1) return h;
    if(x%2==0)
    {
        vector <pair<int,pair<int,int> > > ans1=degree(h,x/2);
        return mul1(ans1,ans1);
    }
    else
    {
        vector <pair<int,pair<int,int> > > ans1=degree(h,x-1);
        return mul1(ans1,h);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<20;++i)
    {
        for(int j=0;j<20;++j)
        {
            if(i<j)
            {
                c1[i][j]=0;
                continue;
            }
            if(i==j || j==0)
            {
                c1[i][j]=1;
                continue;
            }
            c1[i][j]=c1[i-1][j-1]+c1[i-1][j];
            c1[i][j]%=p;
        }
    }
    int n;
    cin>>n>>k>>c;
    answ.resize(k+1);
    for(int i=0;i<=k;++i) answ[i].resize(1<<c);
    int a[n];
    int o1=0;
    for(int i=0;i<n;++i) {cin>>a[i];o1^=a[i];}
    int b[n];
    for(int i=0;i<n;++i)
    {
        int x=a[i];
        while(true)
        {
            int u=maxbit(x);
            if((x-(1<<u))>=k)
            {
                x-=(1<<u);
            }
            else
            {
                break;
            }
        }
        b[i]=x;
    }
    sort(b,b+n);
    for(int i=0;i<n;++i)
    {
         cnt[b[i]]++;
    }
    dp.resize(k+1);
    for(int i=0;i<=k;++i)
    {
        dp[i].resize(1<<c);
        for(int j=0;j<(1<<c);++j)
        {
            dp[i][j]=0;
        }
    }
    dp[0][0]=1;
    for(int i=0;i<(1<<c);++i)
    {
         if(!cnt[i]) continue;
         vector <pair<int,pair<int,int> > > h;
         for(int j=0;j<=k;++j)
         {
             h.push_back({1,{j,i^(i-j)}});
         }
         vector <pair<int,pair<int,int> > > g=degree(h,cnt[i]);
         mul(dp,build(g));
    }
    vector <int> ans(1<<c);
    for(int i=0;i<(1<<c);++i)
    {
        ans[i^o1]=dp[k][i];
    }
    for(int i=0;i<(1<<c);++i)
    {
        ans[i]*=po(inv(n),k);
        ans[i]%=p;
    }
    for(int i=0;i<(1<<c);++i) cout<<ans[i]<<' ';
    return 0;
}