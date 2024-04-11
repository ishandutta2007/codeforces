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
const int N=1e5+10,M=1e6+10;

int p[M][2],a[N],n,h[M];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        h[a[i]]++;
        if (!p[a[i]][0]) p[a[i]][0]=i;
        p[a[i]][1]=i;
    }
    int num=*max_element(h+1,h+M),L=0,R=n+1;
    FOR(i,1,n) if (h[a[i]]==num){
        if (R-L>p[a[i]][1]-p[a[i]][0])
            L=p[a[i]][0],R=p[a[i]][1];
    }
    cout<<L<<" "<<R;
}