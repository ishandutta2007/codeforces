#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;map<int,int> ma;int a[n];for(int i=0;i<n;++i) {cin>>a[i];ma[a[i]]=i;}
        int cur=n-1;while(cur>=1 && a[cur-1]<=a[cur]) --cur;
        int r=cur;int l=0;set<int> o;
        while(l!=r) {o.insert(a[l]);r=max(r,ma[a[l]]+1);++l;}
        cout<<o.size()<<'\n';
    }
    return 0;
}