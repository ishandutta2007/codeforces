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
const int N=2e5+10;

map <int,int> ma;
int n,m,k,x,y,b[N]={0},pos[N],L[N],R[N],g[N];
char ch;
void add(int x,int v){
    while (x<=m){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int x){
    int ans=0;
    while (x){
        ans+=b[x];
        x-=x&-x;
    }
    return ans;
}
int main(){
    scanf("%d%d%d",&m,&k,&n);
    int top=1,gr=0;
    REP(i,0,m) if (!pos[i]){
        L[++gr]=top;
        int cur=i;
        do{
            g[cur]=gr;
            pos[cur]=top++;
            cur=(cur+k)%m;
        }while (cur!=i);
        R[gr]=top-1;
    }
    ll ans=0;
    //REP(i,0,m) printf("%d ",pos[i]);ENDL;
    while (n--){
        scanf("\n%c%d",&ch,&x);
        //printf("%c %d\n",ch,x);
        if (ch=='-'){
            int pos=ma[x];
            ma.erase(x);
            add(pos,-1);
        }else{
            scanf("%d",&y);
            //printf("%d\n",y);
            int gr=g[y],st;
            y=pos[y];
            if (get(R[gr])-get(y-1)==R[gr]-y+1){
                ans+=R[gr]-y+1;
                st=L[gr];
            }else st=y;
            int cL=st,cR=R[gr],v=get(st-1);
            //printf("%d %d %d\n",cL,cR,y);
            while (cL<=cR){
                int M=(cL+cR)/2;
                if (get(M)-v==M-st+1) cL=M+1;
                else cR=M-1;
            }
            ans+=cL-st;
            //printf("%d\n",cL);
            add(cL,1);
            ma[x]=cL;
        }
        //FOR(i,1,m) printf("%d ",get(i));ENDL;
    }
    cout<<ans;
}