#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

struct query{
    int x,y,k,y1,y2;
    query(int _x,int _y,int _k,int _y1,int _y2){
        x=_x;y=_y;k=_k;y1=_y1;y2=_y2;
    }
};
struct Node{
    int v;
    Node *ls,*rs;
    Node (int _v=0,Node *L=NULL,Node *R=NULL){
        v=_v;ls=L;rs=R;
    }
    Node *Supdate(int L,int R,int val){
        if (val>R||val<L) return this;
        Node *tmp=new Node((this->v+1),(L<R)?this->ls->Supdate(L,(L+R)/2,val):NULL,(L<R)?this->rs->Supdate((L+R)/2+1,R,val):NULL);
        return tmp;
    }
};
Node *root[N];
int w[N]={0},lv[N],p[N][20],n,m,x,y,k,y1;
vector <int> a[N];
int LCA(int x,int y){
    if (lv[x]<lv[y]) swap(x,y);
    int tmp=lv[x]-lv[y];
    while (tmp){
        x=p[x][__builtin_ffs(tmp)-1];
        tmp-=tmp&-tmp;
    }
    if (x==y) return x;
    FORD(i,int(log2(lv[x])),0) if (p[x][i]!=p[y][i])
        x=p[x][i],y=p[y][i];
    return p[x][0];
}
int Kth_vertex(int x,int y,int z,int k){
    int c1=lv[x]-lv[z],c2=lv[y]-lv[z];
    if (k>c1+c2) return -1;
    if (k>c1) k=c1+c2-k,swap(x,y);
    FOR(i,0,18) if (k&(1<<i)) x=p[x][i];
    return x;
}
int get(Node *x,int L,int R,int l,int r){
    if (l>R||r<L) return 0;
    if (l<=L&&R<=r) return x->v;
    return get(x->ls,L,(L+R)/2,l,r)+get(x->rs,(L+R)/2+1,R,l,r);
}
void DFS(int x){
    for(auto i:a[x]){
        root[i]=root[x]->Supdate(0,m,w[i]);
        p[i][0]=x;
        lv[i]=lv[x]+1;
        DFS(i);
    }
}
Node* build(int L,int R){
    Node *tmp=new Node(L==0,(L<R)?build(L,(L+R)/2):NULL,(L<R)?build((L+R)/2+1,R):NULL);
    return tmp;
}
int main(){
    //INPUT;
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&x);
        a[x].push_back(i);
    }
    scanf("%d",&m);
    vector <query> B;
    FOR(i,1,m){
        int type;
        scanf("%d",&type);
        if (type==1){
            scanf("%d",&x);
            w[x]=i;
        }else {
            scanf("%d%d%d%d",&x,&y,&k,&y1);
            B.push_back(query(x,y,k,y1,i));
        }
    }
    root[0]=build(0,m);
    DFS(0);
    FOR(i,1,18)
        FOR(j,1,n) p[j][i]=p[p[j][i-1]][i-1];
    for(auto &i:B){
        int z=LCA(i.x,i.y),L=0,R=lv[i.x]+lv[i.y]-2*lv[z],len=R;
        if (w[i.x]<=i.y1||w[i.x]>i.y2) i.k++;
        while (L<=R){
            int M=(L+R)>>1,cur=Kth_vertex(i.x,i.y,z,M),clca=LCA(i.x,cur);
            int v=get(root[i.x],0,m,i.y1+1,i.y2)+get(root[cur],0,m,i.y1+1,i.y2)-get(root[clca],0,m,i.y1+1,i.y2)-get(root[p[clca][0]],0,m,i.y1+1,i.y2);
            if (M+1-v>=i.k) R=M-1;
            else L=M+1;
        }
        printf("%d\n",(L<len)?Kth_vertex(i.x,i.y,z,L):-1);
    }
}