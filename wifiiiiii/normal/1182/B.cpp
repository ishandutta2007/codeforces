
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

int a[505][505];
set<pair<int,int>> s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int h,w;
    cin>>h>>w;
    rep(i,h) rep(j,w)
    {
        char c;
        cin>>c;
        if(c=='*') a[i][j]=1;
        else a[i][j]=0;
    }
    int xi=0,xj=0,cnt=0;
    for(int i=2;i<=h-1;++i)
    {
        for(int j=2;j<=w-1;++j)
        {
            if(a[i][j] && a[i-1][j] && a[i+1][j] && a[i][j-1] && a[i][j+1]) xi=i,xj=j,cnt++;
        }
    }
    if(cnt!=1) {cout<<"NO"<<endl;return 0;}
    for(int i=xi;i<=h;++i)
    {
        if(a[i][xj]) s.insert({i,xj});
        else break;
    }
    for(int i=xi;i>=0;--i)
    {
        if(a[i][xj]) s.insert({i,xj});
        else break;
    }
    for(int i=xj;i<=w;++i)
    {
        if(a[xi][i]) s.insert({xi,i});
        else break;
    }
    for(int i=xj;i>=1;--i)
    {
        if(a[xi][i]) s.insert({xi,i});
        else break;
    }
    int ok = 1;
    for(int i=1;i<=h;++i)
        for(int j=1;j<=w;++j)
        {
            if(a[i][j] && s.find({i,j})==s.end()) ok=0;
        }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}