#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

unordered_map<int, int> mp;
queue<int> q;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        int tmp;
        cin>>tmp;
        if(mp[tmp]) continue;
        q.push(tmp);
        mp[tmp] = 1;
        if(q.size() > k)
        {
            int cur = q.front();
            mp[cur] = 0;
            q.pop();
        }
    }
    cout<<q.size()<<endl;
    vector<int> ans;
    while(!q.empty()) ans.push_back(q.front()),q.pop();
    reverse(all(ans));
    for(int i:ans) cout<<i<<" ";
    cout<<endl;
}