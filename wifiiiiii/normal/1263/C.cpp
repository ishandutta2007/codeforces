#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
//random_device rng;
//mt19937 rd(rng());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> ans;
        for(int i=1,r;i<=n;i=r+1)
        {
            r=n/(n/i);
            ans.push_back(n/i);
        }
        ans.push_back(0);
        sort(all(ans));
        cout<<ans.size()<<endl;
        for(int i:ans)cout<<i<<" ";cout<<endl;
    }
}