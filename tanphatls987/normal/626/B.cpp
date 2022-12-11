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
const int N=2e2+10;
const int gr[3]={'B','G','R'};

int c[3],h[N][N][N],n;
string s;
struct info{
    int a[3];
    info (int x,int y,int z){
        a[0]=x;a[1]=y;a[2]=z;
    }
};
queue <info> q;
int cv(char ch){
    int ans=0;
    while (gr[ans]!=ch) ans++;
    return ans;
}
void check(info cur,int x,int y){
    cur.a[x]--,cur.a[y]--;
    FOR(i,0,2) if (cur.a[i]<0) return;
    if (x!=y) cur.a[3-x-y]++;
    else cur.a[x]++;
    if (!h[cur.a[0]][cur.a[1]][cur.a[2]]){
        h[cur.a[0]][cur.a[1]][cur.a[2]]=1;
        q.push(cur);
    }
}
int main(){
    cin>>n>>s;
    for(auto ch:s) c[cv(ch)]++;
    h[c[0]][c[1]][c[2]]=1;
    q.push(info(c[0],c[1],c[2]));
    while (!q.empty()){
        info cur=q.front();q.pop();
        FOR(i,0,2)
            FOR(j,i,2) check(cur,i,j);
    }
    if (h[1][0][0]) printf("B");
    if (h[0][1][0]) printf("G");
    if (h[0][0][1]) printf("R");
}