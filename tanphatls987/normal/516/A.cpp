#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("a.inp","r",stdin)
#define OUTPUT freopen("a.out","w",stdout)
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
const int N=10;

int n,h[N]={0};
string s;
int main(){
    cin>>n>>s;
    REP(i,0,n){
        int x=s[i]-'0';
        FOR(j,2,x){
            int cur=j;
            FOR(k,2,j) while (cur%k==0) h[k]++,cur/=k;
        }
    }
    //FOR(i,1,9) printf("%d ",h[i]);
    FORD(i,9,2){
        FOR(j,1,h[i]) printf("%d",i);
        FOR(j,2,i){
            int cur=j;
            FOR(k,2,j) while (cur%k==0) h[k]-=h[i],cur/=k;
        }
    }
}