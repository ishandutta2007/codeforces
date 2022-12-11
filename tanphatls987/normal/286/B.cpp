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
const int N=1e6+10;

int p[N<<1],n;
int main(){
    cin>>n;
    REP(i,0,n) p[i]=i+1;
    int L=0,R=n-1;
    FOR(phase,2,n){
        for(int j=L+(n-1)/phase*phase;j>=L;j-=phase) p[min(j+phase,R+1)]=p[j];
        L++,R++;
//        FOR(i,L,R) cout<<p[i]<<" \n"[i==R];
    }
    FOR(i,L,R) printf("%d ",p[i]);
}