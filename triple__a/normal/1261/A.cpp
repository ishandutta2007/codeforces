#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=2007;
int t,n,k,ans=0;
string s;
int ret[maxn],now[maxn];
vector<PI> vec;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        vec.clear();
        cin>>n>>k>>s;
        for (int i=1;i<=n;++i){
            if (s[i-1]=='(') now[i]=1;
            else now[i]=0;
        }
        for (int i=1;i<=n/2-k+1;++i){
            ret[i]=1;
            ret[i+n/2-k+1]=0;
        }
        for (int i=1;i<=k-1;++i){
            ret[n-2*i+2]=0;
            ret[n-2*i+1]=1;
        }
        for (int i=1;i<=n;++i){
            if (now[i]==ret[i]) vec.push_back({i,i});
            else{
                for (int j=i+1;j<=n;++j){
                    if (now[j]==ret[i]){
                        vec.push_back({i,j});
                        int l=i,r=j;
                        while (l<=r){
                            swap(now[l++],now[r--]);
                        }
                        break;
                    }
                }
            }
        }
        cout<<n<<endl;
        for (auto c:vec){
            cout<<c.F<<" "<<c.S<<endl;
        }
    }
    return 0;
}