#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("c.inp","r",stdin)
#define OUTPUT freopen("c.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ll,int> lli;

const int inf=1e9;
const int MOD=1e9+7;
const int N=6e6;

int t[N+10];
ll n,cur;
vector <int> pri;
vector <lli> a;
vector <ll> b;
ll cube(ll x){
    return x*x*x;
}
void DP(int x){
    if (x==a.size()){
        b.push_back(cur);
        return;
    }
    FOR(i,0,a[x].Y){
        DP(x+1);
        if (i<a[x].Y) cur*=a[x].X;
    }
    FOR(i,1,a[x].Y) cur/=a[x].X;
}
int main(){
    FOR(i,2,N) if (!t[i]){
        pri.push_back(i);
        for(ll j=1LL*i*i;j<=N;j+=i) t[j]=i;
    }
    cin>>n;
    ll ans=0;
    if (n%3==0){
        n/=3;
        ll tmp=n;
        for(auto i:pri) {
            if (1LL*i*i>n) break;
            if (n%i==0){
                int c=0;
                while (n%i==0) n/=i,c++;
                a.push_back(lli(i,c));
            }
        }
        if (n>1) a.push_back(lli(n,1));
        n=tmp;
        //for(auto i:a) printf("%lld %d\n",i.X,i.Y);
        cur=1;
        DP(0);
        //
        sort(b.begin(),b.end());
        int m=b.size();
        //for(auto i:b) printf("%lld\n",i);
        //cout<<n<<'\n';
        for(int i=0;i<m&&cube(b[i])<=n;i++)
            for(int j=i;j<m&&b[i]*b[j]*b[j]<=n;j++) if (n%(b[i]*b[j])==0){
                //cout<<b[i]<<" "<<b[j]<<" "<<n/(b[i]*b[j])<<" ";
                //ll z=n/(b[i]*b[j])-b[i]+b[j],x=b[j]-z,y=b[i]-x;
                ll x=b[i]+b[j]-n/(b[i]*b[j]);
                if (x%2) continue;x>>=1;
                ll y=b[i]-x,z=b[j]-x;
                //cout<<x<<" "<<y<<" "<<z<<'\n';
                if (x<=0||y<=0||z<=0) continue;
                if (x==y){
                    if (z==x) ans++;
                    else ans+=3;
                }else{
                    if (y==z) ans+=3;
                    else ans+=6;
                }
            }
    }
    cout<<ans;
}