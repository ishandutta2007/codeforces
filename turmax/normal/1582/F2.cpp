#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int maxa=8192;
int s[maxa];
vector <int> r[maxa];
bool h[maxa][maxa];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=0;i<maxa;++i) for(int j=0;j<maxa;++j) {r[i].push_back(j);h[i][j]=true;}
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    for(int j=0;j<maxa;++j) s[j]=10000;
    s[0]=(-10000);
    for(int i=0;i<n;++i)
    {
        for(int j:r[a[i]])
        {
            h[a[i]][j]=false;
            if(s[j]<=a[i]) continue;
            if(s[j^a[i]]<a[i])
            {
                for(int k=a[i]+1;k<min(maxa,s[j]);++k)
                {
                    if(!h[k][j^k]) {r[k].push_back(j^k);h[k][j^k]=true;}
                }
                s[j]=a[i];
            }
        }
        r[a[i]].clear();
    }
    vector <int> res;
    for(int i=0;i<maxa;++i) if(s[i]!=10000) res.push_back(i);
    cout<<res.size()<<'\n';
    for(auto h:res) cout<<h<<' ';
    return 0;
}