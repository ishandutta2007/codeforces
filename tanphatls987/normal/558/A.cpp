#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
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

int n,x,y;
vector <ii> q[2];
int main(){
    cin>>n;
    FOR(i,1,n){
        cin>>x>>y;
        if (x<0) q[1].push_back(ii(-x,y));
        else q[0].push_back(ii(x,y));
    }
    FOR(i,0,1) sort(q[i].begin(),q[i].end());
    int n0=q[0].size(),n1=q[1].size(),sum=0;
    REP(i,0,min(n0,n1+1)) sum+=q[0][i].Y;
    REP(i,0,min(n1,n0+1)) sum+=q[1][i].Y;
    cout<<sum;
}