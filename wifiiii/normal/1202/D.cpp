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

ll a[100005];
map<int,int> mp;
const int N = 44720;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(int i=1;i<=N;++i) a[i]=i*(i+1)/2,mp[a[i]]=i;
    int t;
    cin>>t;
    while(t--)
    {
        ans.clear();
        int n;
        cin>>n;
        for(int i=N;i>=1;--i)
        {
            if(mp.count(n))
            {
                ans.push_back(mp[n]);
                n = 0;
                break;
            }
            if(n>=a[i]) n-=a[i],ans.push_back(i);
        }
        while(n) ans.push_back(1),n--;
        sort(all(ans));
        vector<int> ret;
        ret.push_back(1);
        for(int p=0;p<=ans[0];++p) ret.push_back(3);ret.push_back(7);
        for(int k=1;k<ans.size();++k)
        {
            for(int p=0;p<ans[k]-ans[k-1];++p) ret.push_back(3);
            ret.push_back(7);
        }
        for(int i:ret) cout<<i;
        cout<<endl;
    }
}