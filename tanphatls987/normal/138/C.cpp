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
const int N=1e5+10;

int n,m,h[105];
ii b[N],a[N<<2];
int main(){
    scanf("%d%d",&n,&m);
    REP(i,0,n){
        int x,h,l,r;
        scanf("%d%d%d%d",&x,&h,&l,&r);
        a[4*i]=ii(x-h,101-l);
        a[4*i+1]=ii(x,-(101-l));
        a[4*i+2]=ii(x+1,101-r);
        a[4*i+3]=ii(x+h+1,-(101-r));
    }
    sort(a,a+4*n);
    FOR(i,1,m) scanf("%d%d",&b[i].X,&b[i].Y);
    sort(b+1,b+m+1);
    double ans=0;
    for(int i=1,j=0;i<=m;i++){
        while (j<4*n&&a[j].X<=b[i].X){
            int v=abs(a[j].Y)-1,sign=(a[j].Y<0)?-1:1;
            h[v]+=sign;
            j++;
        }
        double pro=1;
        FOR(k,0,100) if (h[k]) pro*=pow((k+.0)/100,h[k]);
        ans+=pro*b[i].Y;
    }
    printf("%.6f",ans);
}