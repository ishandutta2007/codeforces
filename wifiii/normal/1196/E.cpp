#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
const int mod = 1e9+7;

int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        vector<pair<int,int>> ans;
        int b,w;
        cin>>b>>w;
        int sx=2,sy=2;
        if(w>b) sx=2,sy=3,swap(b,w);
        //w<=b
        if(b>3*w+1) {cout<<"NO"<<endl;continue;}
        for(int i=0;i<w;++i) ans.push_back({sx+i*2,sy});
        for(int j=0;j<=w;++j)
        {
            if(!b) break;
            b--;
            ans.push_back({sx+2*j-1,sy});
        }
        for(int i=0;i<w;++i)
        {
            if(!b) break;
            b--;
            ans.push_back({sx+i*2,sy-1});
        }
        for(int i=0;i<w;++i)
        {
            if(!b) break;
            b--;
            ans.push_back({sx+i*2,sy+1});
        }
        cout<<"YES"<<endl;
        for(auto p:ans) cout<<p.first<<" "<<p.second<<endl;
    }
}