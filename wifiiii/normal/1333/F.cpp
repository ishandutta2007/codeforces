#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 500005;
int prime[maxn],np[maxn],mp[maxn],tot=0;
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
            mp[i*prime[j]] = prime[j];
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    vector<int> v;
    int cnt = 1;
    for(int i=2;i<=n;++i) if(!np[i]) ++cnt;else v.push_back(i);
    sort(v.begin(),v.end(),[&](int i,int j){return i/mp[i]<j/mp[j];});
    for(int i=2;i<=n;++i) {
        if(i<=cnt) cout<<1<<" ";
        else cout<<v[i-cnt-1]/mp[v[i-cnt-1]]<<" ";
    }
    cout<<endl;
}