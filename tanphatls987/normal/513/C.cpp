#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
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
const int N=1e4+10;

int n;
ii a[10];
double f[N];
int main(){
    cin>>n;
    REP(i,0,n) cin>>a[i].X>>a[i].Y;
    double ans=0;
    REP(k,1,1<<n){
        f[0]=0;
        int m1=__builtin_popcount(k);
        if (m1==1){
            FOR(j,0,10000){
                f[j]=1.0;
                double pro=1.0;
                int R=inf,L=j+1;
                REP(i,0,n) if (!(k&(1<<i))){
                    if (j<a[i].X) f[j]=0;
                    else f[j]*=(min(j,a[i].Y)-a[i].X+1.0)/(a[i].Y-a[i].X+1);
                }else {
                    R=min(R,a[i].Y);
                    L=max(a[i].X,L);
                }
                if (L>R) continue;
                REP(i,0,n) if (k&(1<<i)) pro*=(R-L+1.0)/(a[i].Y-a[i].X+1);
                if (j) ans=ans+j*(f[j]-f[j-1])*pro;
                else ans=ans+j*f[j]*pro;
                    //r+=(f[j]-f[j-1])*pro;
            }
        }else{
            double last=.0;
            FOR(j,0,10000){
                f[j]=1.0;
                //double pro=1.0;
                int R=inf,L=j+1;
                REP(i,0,n) if (!(k&(1<<i))){
                    if (j<a[i].X) f[j]=0;
                    else f[j]*=(min(j,a[i].Y)-a[i].X+1.0)/(a[i].Y-a[i].X+1);
                }else {
                    R=min(R,a[i].Y);
                    L=max(a[i].X,L);
                }
                if (L>R) continue;
                if (j) last=last+(f[j]-f[j-1])*(R+L)*(R-L+1)/2;
                else last=last+f[j]*(R+L)*(R-L+1)/2;
                //printf("%d %d %d %d %.10f\n",k,j,L,R,last);
            }

            REP(i,0,n) if (k&(1<<i)) last*=1.0/(a[i].Y-a[i].X+1);
            ans+=last;
        }
    }
    printf("%.11f",ans);
}