#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
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
const int N=2e5+10,M=1e6+10;

int n,m,x,type,link[M][2],car[N],pos[M],np[M][2],h[M],top=0;
struct range{
    int L,R,pos,idx,len;
    range(int _L=0,int _R=0,int _pos=0,int _idx=0){
        L=_L,R=_R;idx=_idx;pos=_pos;
        len=min(L?pos-L:inf,(R<n)?R-pos:inf);
    }
};
class comp{
    public:bool operator ()(range a,range b){
        if (a.len==b.len) return a.pos>b.pos;
        return a.len<b.len;
    }
};
priority_queue <range,vector<range>,comp> q;
void set_link(int x,int y){
    link[x][1]=y;
    link[y][0]=x;
    int L=pos[x],R=pos[y];
    if (L+1==R) return;
    int ncar=(L?(R==n?n-1:(L+R)/2):1);
//    printf("%d %d %d %d\n",L,R,ncar,top);
    q.push(range(L,R,ncar,++top));
    np[x][1]=np[y][0]=top;

}
int park(int x){
    range cur;
    while (1){
        cur=q.top();q.pop();
        if (!h[cur.idx]) break;
    }
    int Lcar=car[cur.L],Rcar=car[cur.R];
    pos[x]=cur.pos;
    car[cur.pos]=x;
    set_link(Lcar,x);
    set_link(x,Rcar);


    return pos[x];
}
void depart(int x){
    h[np[x][0]]=h[np[x][1]]=1;
    set_link(link[x][0],link[x][1]);
}
void init(){
    car[0]=M-1,car[++n]=M-2;
    pos[M-1]=0;pos[M-2]=n;
    set_link(M-1,M-2);
}
int main(){
//    INPUT;
    scanf("%d%d",&n,&m);
    init();
    while (m--){
        scanf("%d%d",&type,&x);
//        printf("%d %d\n",type,x);
        if (type==1) printf("%d\n",park(x));
        else depart(x);
    }
}