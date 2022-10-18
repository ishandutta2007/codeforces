#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    bool ok=0;
    vector<int> v(k);
    rep(i,k) cin>>v[i];
    if(*max_element(ALL(v))>=1ll*m*n) ok=1;
    else{
        if(v.size()>=2){
            LL s=0;
            LL c=0;
            for(auto it:v){
                if(it/n>=2)
                s+=it/n,c+=it/n-2;
            }
            if(s>=m){
                if(s>m){
                    if(s-c<=m){
                        ok=1;
                    }
                    else{
                        if(c>=1||s%2==m%2)
                        ok=1;
                    }
                }
                else{
                    ok=1;
                }
            }
            swap(n,m);
            s=0;
            c=0;
            for(auto it:v){
                if(it/n>=2)
                s+=it/n,c+=it/n-2;
            }
            if(s>=m){
                if(s>m){
                    if(s-c<=m){
                        ok=1;
                    }
                    else{
                        if(c>=1||s%2==m%2)
                        ok=1;
                    }
                }
                else{
                    ok=1;
                }
            }
        }
    }
    if(ok) cout<<"Yes\n";
    else cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}