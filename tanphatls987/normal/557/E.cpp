#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=5e3+10,alpha=2;

int g[N][N],s[N],n,m,f[alpha],c[N];
string st;
queue <int> hpal[N];
bool check(int x,int y){
    if (x>y) return 1;
    return g[x][y];
}
int main(){
    cin>>st>>m;
    int n=st.length();
    FOR(i,1,n)
        FORD(j,i,1) g[j][i]=(st[i-1]==st[j-1]&&check(j+2,i-2));
//    FOR(i,1,n)
//        FOR(j,1,n) cout<<g[i][j]<<" \n"[j==n];
    FOR(i,1,n)
        FOR(j,i,n) if (check(i,j)) {
//            printf("%d %d\n",i,j);
            hpal[i].push(j);
            c[i]++;
        }
//    FOR(i,1,n) printf("%d ",c[i]);ENDL;
    int top=n;
    FOR(i,1,n) s[i]=i;
    for(int pos=0;m>0;pos++){
//        printf("%d %d\n",pos,m);
        memset(f,0,sizeof(f));
        FOR(i,1,top){
            int cur=s[i];
            if (cur+pos>n) continue;
            f[st[cur+pos-1]-'a']+=c[cur];
        }
        int sel=0;
        while (m>f[sel]) m-=f[sel++];
        int ltop=top;
        top=0;
        FOR(i,1,ltop){
            int cur=s[i];
            if (st[cur+pos-1]-'a'==sel) s[++top]=cur;
        }
        printf("%c",sel+'a');
        FOR(i,1,top){
            int cur=s[i];
            if (!hpal[cur].empty()&&hpal[cur].front()-cur==pos) {
                m--;
                c[cur]--;
                hpal[cur].pop();
            }
        }
    }
}