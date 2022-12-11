#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("630.inp","r",stdin)
#define OUTPUT freopen("630.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=0;
const int d[5]={0,2,4,3,1};

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int delta=b*b-4*a*c;
    double ans1=(-b+sqrt(delta))/(2*a),ans2=(-b-sqrt(delta))/(2*a);
    if (ans1<ans2) swap(ans1,ans2);
    printf("%.12f\n%.12f",ans1,ans2);
}