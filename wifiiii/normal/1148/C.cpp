
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
int a[300005],b[300005],idx[300005];
vector<pair<int,int>> ans;
void sw(int x,int y)
{
    int tmp1=a[x],tmp2=a[y];
    swap(a[x],a[y]);
    swap(idx[tmp1],idx[tmp2]);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,n)
    {
        cin>>a[i];
        b[i]=a[i];
        idx[a[i]]=i;
    }
    rep(i,n)
    {
        //int tmp = idx[i];
        if(idx[i]<=n/2)
        {
            ans.push_back({idx[i],n});
            sw(idx[i],n);
            if(i<=n/2)
            {
                ans.push_back({n,i});
                sw(n,i);
                //ans.push_back({tmp,n});
                //sw(tmp,n);
            }
            else
            {
                ans.push_back({1,n});
                ans.push_back({1,i});
                
                sw(1,n);
                sw(1,i);
                
            }
        }
        else
        {
            ans.push_back({idx[i],1});
            sw(idx[i],1);
            if(i>n/2)
            {
                sw(1,i);
                ans.push_back({1,i});
                
            }
            else
            {
                sw(1,n);
                sw(i,n);
                ans.push_back({1,n});
                ans.push_back({i,n});
            }
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
}