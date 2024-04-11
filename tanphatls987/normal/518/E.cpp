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
#define OUT {printf("Incorrect sequence");return;}

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

char s[12];
int n,k,a[N<<1];
void solve(){
    FOR(i,1,k){
        int L=-inf;
        for(int j=i;j<=n;j+=k) if (a[j]==-inf){
            int pos=j,c=0;
            while (pos<=n&&a[pos]==-inf) pos+=k,c++;
            if (pos>n) a[pos]=inf;
            if (a[pos]<L+c) OUT;
            if (a[pos]>0){
                L=max(L,min(-(c/2),a[pos]-c));
                a[j]=L;
                for(int j1=j+k;j1<pos;j1+=k) a[j1]=a[j1-k]+1;
            }else for(int j1=pos-k;j1>=j;j1-=k) a[j1]=a[j1+k]-1;
            L=a[pos]+1;
            j=pos;
        }else{
            if (j>k&&a[j]<=a[j-k]) OUT;
            L=a[j]+1;
        }
    }
    FOR(i,1,k)
        for(int j=i;j<=n-k;j+=k) if (a[j]>=a[j+k]) OUT;
    FOR(i,1,n) printf("%d ",a[i]);
}
int main(){
    scanf("%d%d\n",&n,&k);
    FOR(i,1,n){
        scanf("%s ",s);
        if (s[0]=='?') {
            a[i]=-inf;
            continue;
        }
        int sign=1,m=strlen(s);
        if (s[0]=='-') sign=-1;
        REP(j,s[0]=='-',m) a[i]=10*a[i]+s[j]-'0';
        a[i]*=sign;
    }
    solve();
}