#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int a[55],nxta[55],n;
int find(int x) {
    for(int i=1;i<=n;++i) if(a[i]==x) return i;
    return -1;
}
int par[55],sz[55];
int fd(int x) {return x==par[x]?x:par[x]=fd(par[x]);}
void merge(int x,int y) {
    int u=fd(x),v=fd(y);
    if(u != v) {
        if(u > v) swap(u, v);
        par[u] = v;
        sz[v] += sz[u];
    }
}
int chk() {
    ii if(a[i]!=i) return 0;
    return 1;
}
int main() {
    cin>>n;
    ii par[i]=i;
    ii cin>>a[i],sz[i]=1;
    vector<vector<int>> ans;
    while(!chk()) {
        for(int i=1;i<n;++i) {
            if(fd(i) == fd(i+1)) continue;
            int x=find(i),y=find(i+1);
            if(x<y) continue;
            vector<int> v;
            int tmp[4];
            int sz1 = sz[fd(i+1)];
            tmp[0] = y-1, tmp[1] = sz1, tmp[2] = x-tmp[0]-tmp[1], tmp[3] = n-tmp[0]-tmp[1]-tmp[2];
            for(int j=0;j<4;++j) {
                if(tmp[j]) v.push_back(tmp[j]);
            }
            int pos = 1, pos2 = n;
            for(int j : v) {
                int r = j + pos - 1;
                for(int k=r;k>=pos;--k) {
                    nxta[pos2--] = a[k];
                }
                pos += j;
            }
            swap(a, nxta);
            ans.push_back(v);
            merge(i,i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(auto &v : ans) {
        cout<<v.size()<<" ";
        for(int j:v) cout<<j<<" ";cout<<endl;
    }
}