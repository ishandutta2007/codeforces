#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int n,m,d;
const int maxn=2005;
int po[maxn];
int go(string s)
{
    int le[n+1][m];int eq[n+1][m];
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<m;++j)
        {
            le[i][j]=0;eq[i][j]=0;
        }
    }
    eq[0][0]=1;
    for(int i=0;i<n;++i)
    {
        for(int k=0;k<m;++k)
        {
        int x=s[i]-'0';
        int y=po[n-i-1];
        for(int j=0;j<10;++j)
        {
            if(i%2==0 && j==d)
            {
                continue;
            }
            if(i%2==1 && j!=d)
            {
                continue;
            }
            int o=(y*j+k)%m;
            if(j>x)
            {
                le[i+1][o]+=le[i][k];
                le[i+1][o]%=p;
            }
            else if(j==x)
            {
                le[i+1][o]+=le[i][k];
                le[i+1][o]%=p;
                eq[i+1][o]+=eq[i][k];
                eq[i+1][o]%=p;
            }
            else
            {
                le[i+1][o]+=le[i][k];
                le[i+1][o]%=p;
                le[i+1][o]+=eq[i][k];
                le[i+1][o]%=p;
            }
        }
        }
    }
    return le[n][0]+eq[n][0];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>m>>d;
    int u=1;
    for(int i=0;i<maxn;++i)
    {
        po[i]=u;
        u*=10;
        u%=m;
    }
    string s1,s2;
    cin>>s1>>s2;
    n=s1.size();
    int ans1=go(s2)-go(s1);
    int h=0;
    bool z=true;
    for(int i=0;i<n;++i)
    {
        if(s1[i]==('0'+d) && (i%2==0))
        {
            z=false;
        }
        else if(i%2==1 && s1[i]!=('0'+d))
        {
            z=false;
        }
        h+=po[n-i-1]*(s1[i]-'0');
        h%=m;
    }
    if(h==0 && z)
    {
        ++ans1;
    }
    cout<<(ans1%p+p)%p;
    return 0;
}