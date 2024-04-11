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

int n,m,a[N],c[N];
bool check(ll M){
//    cout<<M<<'\n';
    FOR(i,1,n) c[i]=a[i];
    for(int i=1,j=1;i<=m;i++){
        ll cur=M-j;
        while (cur>0){
            ll take=min(ll(c[j]),cur);
            cur-=take;
            c[j]-=take;
            if (!c[j]) j++,cur--;
            if (j>n) return 1;
        }
    }
    return 0;
}
int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    while (!a[n]) n--;
    ll L=1,R=1e15;
    while (L<=R){
        ll M=(L+R)>>1;
        if (check(M)) R=M-1;
        else L=M+1;
    }
    cout<<L;
}