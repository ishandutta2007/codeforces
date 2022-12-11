#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

typedef pair<int,int> ii;
const int N=4e5+10;
int n,m;

ii e[N];
vector <ii> ans;

map <int,int> re[2];
int t[N];
int p[2],d[2],cd[2];
int root(int x){
    if (t[x]<0) return x;
    return t[x]=root(t[x]);
}
bool mergenode(int x,int y){
    int rx=root(x),ry=root(y);
    if (rx==ry) return 0;
    if (t[rx]>t[ry]) swap(rx,ry);
    t[rx]+=t[ry];
    t[ry]=rx;
    return 1;
}
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&e[i].X,&e[i].Y);
    scanf("%d%d%d%d",p,p+1,d,d+1);
    for(int i=1;i<=m;i++) if (e[i].Y==p[0]||e[i].Y==p[1])
        swap(e[i].X,e[i].Y);
    for(int i=1;i<=m;i++) if (e[i].Y==p[0]||e[i].Y==p[1])
        swap(e[i],e[m]);
}
void reset(){
    memset(t,-1,sizeof(t));
    for(int i=0;i<=1;i++) re[i].clear();
    ans.clear();
    cd[0]=cd[1]=0;
}
bool solve(){
    for(int i=1;i<=m;i++) {
        if (e[i].X==p[0]||e[i].X==p[1]) continue;
        if (mergenode(e[i].X,e[i].Y)) ans.push_back(e[i]);
    }
    for(int i=1;i<=m;i++)
        for(int j=0;j<=1;j++) if (e[i].X==p[j]) re[j][root(e[i].Y)]=i;
    for(int type=0;type<=1;type++)
        for(auto i:re[type]) if (!re[type^1][i.X]&&cd[type]<d[type]){
            mergenode(e[i.Y].X,e[i.Y].Y);
            ans.push_back(e[i.Y]);
            cd[type]++;
        }
    for(auto i:re[0]) if (re[1][i.X]){
        for(int j=0;j<=1;j++) {
            int idx=re[j][i.X];
            if (cd[j]<d[j]&&mergenode(e[idx].X,e[idx].Y)) {
                cd[j]++;
                ans.push_back(e[idx]);
            }
        }
    }
    return (ans.size()==n-1);
}
void output(){
    printf("Yes\n");
    for(auto i:ans) printf("%d %d\n",i.X,i.Y);
    exit(0);
}
int main(){
    prepare();
    reset();
    if (e[m].Y==p[0]||e[m].Y==p[1]){
        mergenode(p[0],p[1]);
        ans.push_back(ii(p[0],p[1]));
        m--;
        cd[0]=cd[1]=1;
    }
    if (solve()) output();
    reset();
    if (solve()) output();
    printf("No");
}