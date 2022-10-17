
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

map<int,pair<int,int>> mp;
int a[6] = {4,8,15,16,23,42};
int ans[7];
int main()
{
    for(int i=0;i<6;++i)
        for(int j=i+1;j<6;++j)
            mp[a[i]*a[j]] = {a[i],a[j]};
    int t;
    cout << "? 1 2" << endl;
    cin>>t;
    ans[1]=mp[t].first,ans[2]=mp[t].second;
    cout.flush();
    cout << "? 2 3" << endl;
    cin>>t;
    if(ans[2]==mp[t].first || ans[2]==mp[t].second)
    {
        if(ans[2]==mp[t].first) ans[3]=mp[t].second;
        else ans[3]=mp[t].first;
    }
    else
    {
        swap(ans[1],ans[2]);
        if(ans[2]==mp[t].first) ans[3]=mp[t].second;
        else ans[3]=mp[t].first;
    }
    cout.flush();
    cout << "? 4 5" << endl;
    cin>>t;
    ans[4]=mp[t].first,ans[5]=mp[t].second;
    cout.flush();
    cout << "? 5 6" << endl;
    cin>>t;
    if(ans[5]==mp[t].first || ans[5]==mp[t].second)
    {
        if(ans[5]==mp[t].first) ans[6]=mp[t].second;
        else ans[6]=mp[t].first;
    }
    else
    {
        swap(ans[4],ans[5]);
        if(ans[5]==mp[t].first) ans[6]=mp[t].second;
        else ans[6]=mp[t].first;
    }
    cout.flush();
    cout<<"!";
    for(int i=1;i<=6;++i) cout<<" "<<ans[i];
    cout<<endl;
}