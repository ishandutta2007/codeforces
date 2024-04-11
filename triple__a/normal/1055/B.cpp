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

const int maxn=200007;
int n,q,l,ret=0;
int a[maxn];
bool vis[maxn];


void update(int u,int v){
    if (a[u]>l) return;
    a[u]+=v;
    if (a[u]>l){
        vis[u]=1;
        a[u]=l+1;
        ret++;
//        cout<<u<<" "<<a[u]<<" "<<ret<<" "<<vis[u-1]<<" "<<vis[u+1]<<endl;
        if (u>1&&vis[u-1]) ret--;
        if (u<n&&vis[u+1]) ret--;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    memset(vis,0,sizeof(vis));
    cin>>n>>q>>l;
    rep1(i,n) {int u; cin>>u; update(i,u);}
    while (q--){
        int op,u,v;
        cin>>op;
        if (op){
            cin>>u>>v;
            update(u,v);
        }
        else{
            cout<<ret<<"\n";
        }
    }
    return 0;
}