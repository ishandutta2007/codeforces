#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=3e3+10;

int n;
template <class T>
bool maximize(T &x,T y){
    if (x<y) x=y;else return 0;
    return 1;
}
struct graph{
    vector <int> v[N];
    int good[N][3],rgood[N][3];
    int d[N][N],q[N];
    void BFS(int st){
        d[st][st]=1;
        int top=1,bot=1;
        q[1]=st;
        while (top<=bot){
            int x=q[top++];
            for(auto y:v[x]) if (!d[st][y]){
                d[st][y]=d[st][x]+1;
                q[++bot]=y;
            }
        }
        FORD(i,bot,max(bot-2,2)) good[st][bot-i]=q[i];
    }
    void solve(){
        FOR(i,1,n) BFS(i);
        FOR(i,1,n){
            FOR(x,1,n) {
                if (x!=i&&d[x][i]>d[rgood[i][2]][i]) {
                    rgood[i][2]=x;
                    FORD(j,2,1) if (d[rgood[i][j]][i]>d[rgood[i][j-1]][i])
                        swap(rgood[i][j],rgood[i][j-1]);
                }
            }
        }
        int ans=0;
        vector <int> asel;
        FOR(s2,1,n)
            FOR(s3,1,n) if (s2!=s3&&d[s2][s3]){
                FOR(j,0,2){
                    int s1=rgood[s2][j];
                    if (!d[s1][s2]||s1==s3) continue;
                    FOR(i,0,2){
                        int s4=good[s3][i];
                        if (!d[s3][s4]||s4==s1||s4==s2) continue;
//                        cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<" "<<d[s1][s2]+d[s2][s3]+d[s3][s4]<<'\n';
                        if (maximize(ans,d[s1][s2]+d[s2][s3]+d[s3][s4]))
                            asel={s1,s2,s3,s4};
                    }
                }
            }
//        cout<<ans<<'\n';
        for(auto i:asel) cout<<i<<" ";
    }
}mgr;
void prepare(){
    int m,x,y;
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        mgr.v[x].push_back(y);
    }
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    mgr.solve();
}