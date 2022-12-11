#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=0;

ii a[4];
int sqr(int x){
    return x*x;
}
double dis(int xa,int ya,int xb,int yb){
    return sqrt(sqr(xb-xa)+sqr(yb-ya));
}
int main(){
    int n,m;
    cin>>n>>m;
    if (n==0) printf("0 1\n0 %d\n0 0\n0 %d\n",m,m-1);
    else if (m==0) printf("1 0\n%d 0\n0 0\n%d 0",n,n-1);
    else {
        int n1=min(n,m),m1=n+m-n1,rev=0;
        if (n1!=n) rev=1;
        double mdis=0;
        FOR(i,1,n1)
            REP(j,0,n1){
                double cdis=dis(n1,m1,i,0)+dis(i,0,j,m1);
                if (cdis>mdis){
                    mdis=cdis;
                    a[0]=ii(0,0);
                    a[1]=ii(n1,m1);
                    a[2]=ii(i,0);
                    a[3]=ii(j,m1);
                }
                cdis=dis(i,0,n1,m1)+dis(0,0,j,m1);
                if (cdis>mdis){
                    mdis=cdis;
                    a[0]=ii(i,0);
                    a[1]=ii(n1,m1);
                    a[2]=ii(0,0);
                    a[3]=ii(j,m1);
                }
            }
        if (rev) FOR(i,0,3) swap(a[i].X,a[i].Y);
        FOR(i,0,3) printf("%d %d\n",a[i].X,a[i].Y);
    }
}