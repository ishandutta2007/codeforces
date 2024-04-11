#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;vector<pair<int,int> > v;
    for(int i=0;i<m;++i)
    {
        cout<<"? ";
        for(int j=0;j<m;++j) if(j==i) {cout<<'1';} else {cout<<'0';}
        cout<<endl;
        int ans;cin>>ans;v.push_back({ans,i});
    }
    sort(v.begin(),v.end());
    string cur;for(int i=0;i<m;++i) cur.push_back('0');int ans1=0;
    for(auto [w,x]:v)
    {
        cout<<"? ";
        cur[x]='1';cout<<cur<<endl;
        int ans;cin>>ans;
        if(ans==ans1+w) {ans1+=w;continue;}
        else {cur[x]='0';continue;}
    }
    cout<<"! "<<ans1<<endl;
    return 0;
}