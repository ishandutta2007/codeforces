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
typedef pair<double,int> di;

const int inf=1e9;
const int MOD=1e9+7,BASE=1e9;
const int N=5e3+10;

int ans[N],n,pos[N][2],h[N]={0};
ii a[N];
char s[6];
struct bnum{
    int a[120];
    bnum (int x=0){
        memset(a,0,sizeof(a));
        a[0]=1;
        a[1]=x;
    }
    void print(){
        printf("%d",a[a[0]]);
        FORD(i,a[0]-1,1){
            for(int j=BASE/10;j>1&&j>a[i];j/=10) printf("0");
            printf("%d",a[i]);
        }
    }
};
bnum operator +(bnum x,bnum y){
    x.a[0]=max(x.a[0],y.a[0]);
    FOR(i,1,x.a[0]){
        x.a[i]+=y.a[i];
        x.a[i+1]+=x.a[i]/BASE;
        x.a[i]%=BASE;
    }
    x.a[0]+=(x.a[x.a[0]+1]>0);
    return x;
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("\n%s%d",s,&a[i].Y);
        //printf("%s %d\n",s,a[i].Y);
        a[i].X=(s[0]=='s');
        pos[a[i].Y][a[i].X]=i;
    }
    h[0]=1;
    FORD(i,2000,0) if (pos[i][1]){
        FORD(j,pos[i][1]-1,1) if (a[j].Y==i){
            pos[i][0]=j;
            break;
        }
        bool ok=pos[i][0]<pos[i][1];
        FOR(j,pos[i][0],pos[i][1]) if (h[j]) ok=false;
        if (ok) {
//            printf("%d\n",i);
            ans[i]=1;
            FOR(j,pos[i][0],pos[i][1]) h[j]=1;
        }
    }
    bnum tmp=bnum(1),ret;
    FOR(i,0,2000){
        if (ans[i]) ret=ret+tmp;
        tmp=tmp+tmp;
    }
    ret.print();
}