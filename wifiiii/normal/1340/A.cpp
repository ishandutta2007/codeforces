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

int a[100005],r[100005];
int nxt[100005],lst[100005],sz[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        multiset<int> s;
        ii nxt[i]=i+1,lst[i]=i-1,sz[i]=1;
        ii cin>>a[i],r[a[i]]=i;
        ii s.insert(1);
        int mx = 1, ok = 1;
        for(int i=1;i<=n;++i)
        {
            auto p = s.end();--p;
            mx = *p;
            int k = r[i];
            if(sz[k] < mx) {ok = 0; break;}
            lst[nxt[k]] = lst[k];
            nxt[lst[k]] = nxt[k];
            sz[nxt[k]] += sz[k];
            s.erase(s.find(sz[k]));
            if(nxt[k] != n+1)
            {
                s.erase(s.find(sz[nxt[k]]-sz[k]));
                s.insert(sz[nxt[k]]);
            }
        }
        cout << (ok?"Yes":"No") << endl;
    }
}