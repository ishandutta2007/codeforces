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

const int maxn = 1000005;
int prime[maxn],np[maxn],tot=0;
void init()
{
    np[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
pair<int,int> deg[1005];
vector<pair<int,int>> ans;
int cmp(pair<int,int> a,pair<int,int> b) {return a.first>b.first;}
int main()
{
    init();
    int n;cin>>n;
    int a2=0,a3=0;
    for(int i=1;i<=tot;++i)
    {
        if(prime[i]*2>=n*2 && prime[i]*2<=n*3) {a2=3*n-2*prime[i],a3=n-a2;}
        else continue;
        memset(deg,0,sizeof(deg));ans.clear();
        for(int i=1;i<=a3;++i) deg[i]={3,i};
        for(int i=a3+1;i<=a2+a3;++i) deg[i]={2,i};
        int ok=1;
        for(int i=1;i<=n;++i)
        {
            if(deg[i].first<0 || i+deg[i].first>n) {ok=0;break;}
            for(int j=i+1;j<=i+deg[i].first;++j) deg[j].first--,ans.push_back({deg[i].second,deg[j].second});
            sort(deg+i+1,deg+1+n,cmp);
        }
        if(!ok) continue;
        cout<<ans.size()<<endl;
        for(auto i:ans) cout<<i.first<<" "<<i.second<<endl;
        return 0;
    }
    cout<<-1<<endl;
}