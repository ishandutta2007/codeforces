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
const int N=0;

int cord[3][2];
ii ext_gcd(int x,int y,int &ans){
    int a[3][2]={{x,y},{1,0},{0,1}};
    while (a[0][1]){
        int v=a[0][0]/a[0][1];
        FOR(i,0,2){
            int tmp=a[i][1];
            a[i][1]=a[i][0]-1LL*a[i][1]*v;
            a[i][0]=tmp;
        }
    }
    ans=a[0][0];
    return ii(a[1][0],a[2][0]);
}
ll mul(ll x,ll y,ll mod){
    ll ans=0;
    int sign=(y<0)?-1:1;
    y=abs(y);
    while (y){
        if (y&1) ans=(ans+x)%mod;
        x=(x+x)%mod;
        y>>=1;
    }
    return ans*sign;
}
string solve(){
    if (!cord[2][0]&&!cord[2][1]){
        FOR(i,0,3){
            if (cord[0][0]==cord[1][0]&&cord[0][1]==cord[1][1]) return "YES";
            swap(cord[0][0],cord[0][1]);
            cord[0][1]*=-1;
        }
        return "NO";
    }
    while (cord[2][0]<0||cord[2][1]<0){
        swap(cord[2][0],cord[2][1]);
        cord[2][1]*=-1;
    }
    int re;
    ii bez=ext_gcd(cord[2][0],cord[2][1],re);
    ll com=(1LL*cord[2][0]*cord[2][0]+1LL*cord[2][1]*cord[2][1])/re;
//    printf("%d %d %d %lld\n",re,bez.X,bez.Y,com);
    FOR(i,0,3){
//        printf("%d %d\n",cord[0][0],cord[0][1]);
        int x=cord[1][0]-cord[0][0];
//        printf("%d\n",x);
        if (x%re==0){
            x/=re;
            ll y=mul((mul(cord[2][1],bez.X,com)-mul(cord[2][0],bez.Y,com)),x,com);
//            printf("->%d %lld",x,y+cord[0][1]);
            if ((cord[1][1]-y-cord[0][1])%com==0) return "YES";
        }
        swap(cord[0][0],cord[0][1]);
        cord[0][1]*=-1;
//        ENDL;
    }
    return "NO";
}
int main(){
    FOR(i,0,2)
        FOR(j,0,1) cin>>cord[i][j];
    cout<<solve();
}