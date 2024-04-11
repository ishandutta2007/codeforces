#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("489e.inp","r",stdin)
#define OUTPUT freopen("489e.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const double eps=1e-9;
const int MOD=1e9+7;
const int N=1e3+10;


double f[N];
int t[N],n,len;
vector <int> ans;
ii a[N];
template <class MT>
bool maximize(MT &x,MT y){
    if (x<y) x=y;else return false;
    return true;
}
bool check(double M){
    f[0]=0;
    FOR(i,1,n){
        f[i]=-inf;
        FORD(j,i-1,0) if (maximize(f[i],f[j]-sqrt(abs(a[i].X-a[j].X-len)))) t[i]=j;
        f[i]+=M*a[i].Y;
    }
    if (f[n]>=0){
        ans.clear();
        int x=n;
        while (x){
            ans.push_back(x);
            x=t[x];
        }
        return true;
    }
    return false;
}
int main(){
    scanf("%d%d",&n,&len);
    FOR(i,1,n) scanf("%d%d",&a[i].X,&a[i].Y);
    double L=.0,R=1e6;
    FOR(T,1,80){
        double M=(L+R)/2;
        if (check(M)) R=M-eps;
        else L=M+eps;
    }
    REP(i,ans.rbegin(),ans.rend()) printf("%d ",*i);
}