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

vector <int> pos[N],cur;
int a[N],n,m;
int main(){
    scanf("%d%d",&m,&n);
    FOR(i,1,n){
        scanf("%d",&a[i]);
        pos[a[i]].push_back(i);
    }
    ll cost=0;
    a[0]=a[1],a[n+1]=a[n];
    FOR(i,1,m) if (!pos[i].empty()){
        cur.clear();
        ll red=0;
        for(auto j:pos[i])
            for(int k=-1;k<=1;k+=2)
                if (a[j+k]!=a[j]) {
                    cur.push_back(a[j+k]);
                    red-=abs(a[j]-a[j+k]);
                }
        sort(cur.begin(),cur.end());
        int m1=cur.size();
        for(int L=0,R=m1-1;L<R;L++,R--) red+=cur[R]-cur[L];
        cost=min(cost,red);
        //printf("%d %d\n",cost,red);
    }
    REP(i,1,n) cost+=abs(a[i]-a[i+1]);
    cout<<cost;
}