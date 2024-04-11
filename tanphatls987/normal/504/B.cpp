#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
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
const int N=2e5+10;

struct BIT{
    int b[N],n;
    void update(int x,int v){
        while (x<=n){
            b[x]+=v;
            x+=x&-x;
        }
    }
    int get(int x){
        int tmp=0;
        while (x){
            tmp+=b[x];
            x-=x&-x;
        }
        return tmp;
    }
    int findfre(int v){
        int cur=0,ans;
        for(int i=1<<int(log2(n));i>0;i>>=1){
            int pos=cur+i;
            if (pos>n) continue;
            if (v>b[pos]) v-=b[pos],cur=pos;
            else if (v==b[pos]) ans=pos;
        }
        return ans;
    }
    BIT(int _n){
        memset(b,0,sizeof(b));
        n=_n;
    }
};
int n,p[2][N],f[N];
int main(){
    scanf("%d",&n);
    FOR(j,0,1)
        FOR(i,1,n) scanf("%d",&p[j][i]);
    BIT a(n),b(n);
    FOR(i,1,n) a.update(i,1),b.update(i,1);
    FOR(i,1,n){
        f[i]=a.get(p[0][i])+b.get(p[1][i]);
        a.update(p[0][i]+1,-1);
        b.update(p[1][i]+1,-1);
    }
    //FOR(i,0,n) cout<<f[i]<<" \n"[i==n];
    FORD(i,n-1,1){
        f[i-1]+=f[i]/(n-i+1);
        f[i]%=n-i+1;
    }
    //FOR(i,0,n) cout<<f[i]<<" \n"[i==n];
    FOR(i,1,n) a.update(i,1);
    FOR(i,1,n) {
        int x=a.findfre(f[i]+1);
        printf("%d ",x-1);
        a.update(x,-1);
    }
}