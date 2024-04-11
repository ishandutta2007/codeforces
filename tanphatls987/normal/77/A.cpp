#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9+10;
const int MOD=1e9+7;
const int N=20;
const string name[7]={"Anka","Chapay","Cleo","Troll","Dracul","Snowy","Hexadecimal"};

int v[N][N],n,top[3],s[3][N],w[N];
ii ans;
bool comp(ii a,ii b){
    return (a.X==b.X)?a.Y<b.Y:a.X>b.X;
}
int cv(string s){
    int ans=0;
    while (name[ans]!=s) ans++;
    return ans;
}
ii DFS(int cur){
    if (cur==7){
        FOR(i,0,2) if (!top[i]) return ii(inf,0);
        int ma=0,mi=inf;
        FOR(i,0,2) {
            ma=max(ma,w[i]/top[i]);
            mi=min(mi,w[i]/top[i]);
        }
        ii cur=ii(ma-mi,0);
        FOR(type,0,2)
            FOR(i,1,top[type])
                FOR(j,1,top[type]) cur.Y+=v[s[type][i]][s[type][j]];
        return cur;
    }
    ii ans=ii(inf,0);
    FOR(i,0,2){
        s[i][++top[i]]=cur;
        ans=max(ans,DFS(cur+1),comp);
        top[i]--;
    }
    return ans;
}
void prepare(){
    cin>>n;
    string s1,s2,s3;
    while (n--){
        cin>>s1>>s2>>s3;
        v[cv(s1)][cv(s3)]=1;
    }
    FOR(i,0,2) cin>>w[i];
}
int main(){
    prepare();
    ii ans=DFS(0);
    cout<<ans.X<<" "<<ans.Y<<'\n';
}