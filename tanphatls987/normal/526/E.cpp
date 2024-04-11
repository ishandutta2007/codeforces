#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("e.inp","r",stdin)
#define OUTPUT freopen("e.out","w",stdout)
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
const int N=2e6+10;

int n,q,a[N],p[N];
ll f[N],lim;
int main(){
    //INPUT;OUTPUT;
    scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i),a[n+i]=a[i];
    ll big=0;
    FOR(i,1,n) big+=a[i];
    while (q--){
        scanf("%lld",&lim);
        int ex=(big+lim-1)/lim,top=0;
        f[1]=0;
        int R=0,L=n+1;
        while (R<n&&f[1]+a[R+1]<=lim) f[1]+=a[++R];
        while (L>R+1&&f[1]+a[L-1]<=lim) f[1]+=a[--L];
        FOR(i,1,n) a[i]=a[L+i-1];
        FOR(i,n+1,2*n) a[i]=a[i-n];
        for(int i=0;i<n;){
            f[++top]=0;
            while (i<n&&f[top]+a[i+1]<=lim) f[top]+=a[++i];
            p[top]=i;
        }
        //printf("%d\n",top);
        //FOR(i,1,top) printf("%d %lld\n",p[i],f[i]);
        int ans=top,stop=p[2];
        if (p[1]==1) stop=p[2];
        else stop=p[1];
        for(int pos=2;top>ex&&pos<=stop;pos++){
            f[1]-=a[pos-1];
            if (f[top]+a[pos-1]<=lim) f[top]+=a[++p[top]];
            else {
                f[++top]=a[pos-1];
                p[top]=n+pos-1;
            }
            for(int i=1,j=1,cur=1;i<=top;i++){
                f[i]=f[j];
                p[i]=p[j++];
                while (p[i]<pos+n-1&&f[i]+a[p[i]+1]<=lim){
                    f[i]+=a[++p[i]];
                    f[j]-=a[p[i]];
                    if (p[i]>=p[j]) j++;
                }
                if (j==top+1) top=i;
            }
            //printf(" %d %d\n",pos,top);
            //FOR(i,1,top) printf("%d %lld\n",p[i],f[i]);

            ans=min(ans,top);
        }
        printf("%d\n",ans);
    }
}