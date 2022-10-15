#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int>
 
using namespace std;
 
typedef long long ll;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn=2007;
int t;
int n;
VI vec[maxn];
VI ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>n;
        int mx=0;
        for (int i=0;i<=1000;++i) vec[i].clear();
        rep(i,n) {int u,v; cin>>u>>v; vec[u].pb(v); mx=max(mx,u);}
        for (int i=0;i<=1000;++i) sort(range(vec[i]));
        ans.clear();
        int u=0; 
        for (int i=0;i<=mx;++i){
            if (vec[i].size()){
                if (u>vec[i][0]){
                    cout<<"NO"<<endl;
                    goto cont;
                }
                for (;u<vec[i][vec[i].size()-1];++u){
                    ans.pb(1);
                }
            }
            if (i<mx) ans.pb(0);
        }        
        cout<<"YES"<<endl;
        for (auto c:ans){
            if (c) cout<<"U";
            else cout<<"R";
        }
        cout<<endl;
        cont:;
    }
    return 0;
}