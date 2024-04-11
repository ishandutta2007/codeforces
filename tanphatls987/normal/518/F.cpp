#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("f.inp","r",stdin)
#define OUTPUT freopen("f.out","w",stdout)
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
const int N=2e3+10;

int c[2][N],r[2][N],b[2][N],n,m,a[N][N],stop[N];
char s[N];
void add(int *b,int x,int v,int n){
    while (x<=n){
        b[x]+=v;
        x+=x&-x;
    }
}
int get(int *b,int x){
    int tmp=0;
    while (x){
        tmp+=b[x];
        x-=x&-x;
    }
    return tmp;
}
void prepare(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n){
        scanf("\n%s",s);
        FOR(j,1,m) a[i][j]=s[j-1]=='.';
    }
    FOR(j,1,m) {
        while (a[c[0][j]+1][j]) c[0][j]++;
        c[1][j]=n+1;
        while (a[c[1][j]-1][j]) c[1][j]--;
    }
    FOR(i,1,n){
        while (a[i][r[0][i]+1]) r[0][i]++;
        r[1][i]=m+1;
        while (a[i][r[1][i]-1]) r[1][i]--;
    }
    //FOR(i,1,n) printf("%d %d\n",r[0][i],r[1][i]);
    //FOR(j,1,m) printf("%d %d\n",c[0][j],c[1][j]);
}
ll solve(){
    ll ans=0;
    FOR(i,2,n-1)
        FOR(j,2,m-1)
            ans+=((r[0][i]>=j)+(r[1][i]<=j))*((c[0][j]>=i)+(c[1][j]<=i));
    //printf("tick %d\n",ans);
    stack <int> s[N];
    FOR(i,2,m-1) stop[i]=n;
    FORD(i,n-1,2){
        ans+=r[0][i]==m;
        memset(b,0,sizeof(b));
        FOR(j,2,m-1) add(b[0],j,1,m);
        FOR(j,2,m-1) add(b[1],j,1,m);
        FOR(j,2,m-1) if (!a[i][j]) stop[j]=i;
        FOR(j,2,m-1) if (stop[j]>i&&stop[j]<n) s[stop[j]].push(j);
        FOR(j,i+1,n-1){
            while (!s[j].empty()) {
                FOR(k,0,1) add(b[k],s[j].top(),-1,m);
                s[j].pop();
            }
            if (r[1][j]<=r[0][i]) ans+=get(b[0],r[0][i])-get(b[0],r[1][j]-1);
            if (r[0][j]>=r[1][i]) ans+=get(b[1],r[0][j])-get(b[1],r[1][i]-1);
            if (j-i>1) {
                ans+=get(b[0],min(r[0][i],r[0][j]));
                ans+=get(b[1],m-1)-get(b[1],max(r[1][i],r[1][j])-1);
            }
        }
        //printf("%d %d\n",i,ans);
    }
    //printf("tick %d\n",ans);
    FOR(i,2,n-1) stop[i]=m;
    FORD(i,m-1,2){
        ans+=c[0][i]==n;
        memset(b,0,sizeof(b));
        FOR(j,2,n-1) add(b[0],j,1,n);
        FOR(j,2,n-1) add(b[1],j,1,n);
        FOR(j,2,n-1) if (!a[j][i]) stop[j]=i;
        FOR(j,2,n-1) if (stop[j]>i&&stop[j]<m) s[stop[j]].push(j);
        FOR(j,i+1,m-1){
            while (!s[j].empty()) {
                FOR(k,0,1) add(b[k],s[j].top(),-1,n);
                s[j].pop();
            }
            if (c[1][j]<=c[0][i]) ans+=get(b[0],c[0][i])-get(b[0],c[1][j]-1);
            if (c[0][j]>=c[1][i]) ans+=get(b[1],c[0][j])-get(b[1],c[1][i]-1);
            if (j-i>1){
                ans+=get(b[0],min(c[0][i],c[0][j]));
                ans+=get(b[1],n)-get(b[1],max(c[1][i],c[1][j])-1);
            }
        }
        //printf("%d %d\n",i,ans);
    }
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}