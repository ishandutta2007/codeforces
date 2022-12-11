#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","r",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 0

typedef long long ll;
typedef pair<int,int> ii;

const ll inf=1e16;
const int MOD=1e9+7;
const int N=2e3+10,M=2e3,L=0,R=4e3;

int n,x,y;
ll f[2][N<<1];
int main(){
    scanf("%d",&n);
    FOR(j,0,2*N-10) f[0][j]=inf;
    f[0][M]=0;
    FOR(i,1,n){
        int pre=(i+1)%2;
        scanf("%d%d",&x,&y);
        REP(j,L,R) f[i%2][j]=f[pre][j+1];
        f[i%2][R]=inf;
        deque <int> q;
        FOR(j,L,R){
            while (!q.empty()&&j-q.front()>x) q.pop_front();
            while (!q.empty()&&f[pre][j]<=f[pre][q.back()]) q.pop_back();
            q.push_back(j);
            f[i%2][j]=min(f[i%2][j],f[pre][q.front()]+y);
        }
    }
    cout<<*min_element(f[n%2]+M,f[n%2]+R+1);
}