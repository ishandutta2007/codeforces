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
#define WRONG {printf("-1");return;}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,a[N]={0},T[N][6]={0},ans[N];
void solve(){
    T[0][5]=-1;
    FOR(i,1,n) if (a[i]){
        int j=i+1;
        while (j<=n&&!a[j]) j++;
        if (j<=n){
            if (a[j]<a[i]) WRONG;
            if (a[j]==a[i]) FOR(k,i+1,j) a[k]=a[i];
        }
        i=j-1;
    }
    REP(i,0,n){
        int j=i+1;
        while (j<=n&&!a[j]) j++;
        if (j>n) break;
        if (j==i+1&&a[j]==a[i]){
            FORD(nlen,5,2) if (T[i][nlen-1]) T[j][nlen]=nlen-1;
        }else
        FOR(clen,1,5) if (T[i][clen]){
            FOR(nlen,1,5){
                int nR=j-nlen,nL=i+1+(clen<2);
                if (nR<nL-1) continue;
                int rR=(nR-nL+1)/2,rL=max(nR-i-(5-clen)+4,0)/5;
                if (a[j]-a[i]-1<rL||a[j]-a[i]-1>rR) continue;
                T[j][nlen]=clen;
            }
        }
        //FOR(k,1,5) printf("%d %d %d %d\n",i,j,k,T[j][k]);
        if (count(T[j]+1,T[j]+6,0)==5) WRONG;
        i=j-1;
    }
    ///maximize end part
    int pos=n;
    while (pos&&a[pos]==0) pos--;
    int st=5-(pos==n-1);
    while (st&&!T[pos][st]) st--;
    if (st<=(pos==n)) WRONG;
    FOR(i,pos+1,n) {
        if (i==pos+1) ans[i]=(st<2||i==n)?a[pos]:a[pos]+1;
        else ans[i]=ans[i-1]+(ans[i-1]==ans[i-2]&&i<n);
    }
    ///trace back
    while (pos){
        int nex=pos-1;
        while (nex&&!a[nex]) nex--;
        ///special case
        if (nex==pos-1&&a[nex]==a[pos]){
            ans[pos]=a[pos];
            pos--;st--;
            continue;
        }
        ///fill up
        FORD(i,pos,pos-st+1) ans[i]=a[pos];
        int tmp=st;
        st=T[pos][st];pos-=tmp;

        ///
        if (ans[pos+1]==a[nex]+1)
            FOR(i,nex+1,pos) ans[i]=a[nex];
        else{
            if (st<2) ans[nex+1]=a[nex];
            int each=(pos-nex-(st<2))/(ans[pos+1]-a[nex]-1);
            if (each>=5)
                FORD(i,pos,nex+1) ans[i]=ans[pos+1]-(pos-i)/5-1;
            else{
                int j=pos,add=(pos-nex-(st<2))%(ans[pos+1]-a[nex]-1);
                FOR(i,1,ans[pos+1]-a[nex]-1)
                    FOR(k,1,each+(i<=add)) ans[j--]=ans[pos+1]-i;
            }
        }
        pos=nex;
    }
    printf("%d\n",ans[n]);
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    solve();
}