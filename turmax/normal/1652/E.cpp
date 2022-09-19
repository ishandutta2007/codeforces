#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
const int sq=405;
const int maxn=1e5+5;
const int sz=maxn*(sq+5);
int32_t cnt[sz*2];
vector<int> z;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
    int ans=0;
    for(int d=(-sq);d<=sq;++d)
    {
        z.clear();
        for(int i=0;i<n;++i) {cnt[a[i]-d*i+sz]++;z.push_back(a[i]-d*i+sz);}
        for(auto h:z) {ans=max(ans,(int) cnt[h]);cnt[h]=0;}
    }
    for(int j=0;j<n;++j)
         {
             z.clear();
             for(int k=j+1;k<=min(n-1,j+255);++k)
             {
                 int o=a[k]-a[j];
                 if(o%(k-j)==0)
                 {
                     cnt[o/(k-j)+sz]++;z.push_back(o/(k-j)+sz);
                 }
             }
             for(auto h:z) {ans=max(ans,(int) cnt[h]+1);cnt[h]=0;}
         }
    cout<<n-ans;
    return 0;
}