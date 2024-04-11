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

int t,c,w;
char s[70][70];
bool cr[70],cl[70];
int get_ans(int u,int v){
    int au=4,av=4;
    if (u==0||u==c-1){
        au--;
        if (v==0||v==w-1) au--;
    }
    if (v==0||v==w-1){
        av--;
        if (u==0||u==c-1) av--;
    }
    if (cr[u]) av--;
    if (cl[v]) au--;
    return min(au,av);
}

void check(){
    int ans=0;
    for (int i=0;i<c;++i){
        for (int j=0;j<w;++j){
            if (s[i][j]=='P'){
                ans=5;
                break;
            }
        }
    }
    if (!ans){
        cout<<"0"<<endl;
        return;
    }
    for (int i=0;i<c;++i){
        for (int j=0;j<w;++j){
            if (s[i][j]=='A'){
                ans=min(ans,get_ans(i,j));
            }
        }
    }
    if (ans==5) cout<<"MORTAL"<<endl;
    else cout<<ans<<endl;
    return;
}  
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>t;
    while (t--){
        cin>>c>>w;
        for (int i=0;i<c;++i){
            cin>>s[i];
        }
        for (int i=0;i<c;++i){
            cr[i]=1;
            for (int j=0;j<w;++j){
                if (s[i][j]=='P') cr[i]=0;
            }
        }
        for (int i=0;i<w;++i){
            cl[i]=1;
            for (int j=0;j<c;++j){
                if (s[j][i]=='P') cl[i]=0;
            }
        }
        check();
    }
    return 0;
}