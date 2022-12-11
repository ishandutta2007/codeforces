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
const int N=1e7+10;

int t[N],n,x;
ll h[N];
vector <int> pri;
bool check(ll x){
    bool ans=1;
    for(auto i:pri){
        if (!ans) break;
        ll cur=x,c=0;
        while (cur){
            c+=cur/i;
            cur/=i;
        }
        if (c<h[i]) ans=0;
    }
    return ans;
}
int main(){
    scanf("%d",&n);
    int ma=0;
    ll R=0;
    while (n--){
        scanf("%d",&x);
        h[x]++;
        ma=max(ma,x);
        R+=x;
    }
    FOR(i,2,ma) if (!t[i]){
        pri.push_back(i);
        for(int j=i;j<=ma;j+=i) t[j]=i;
    }
    FORD(i,ma,2) h[i]+=h[i+1];
    ///decompose
    FORD(i,ma,2){
        if (t[i]!=i) h[t[i]]+=h[i];
        h[i/t[i]]+=h[i];
    }
    ll L=ma;
    //printf("tick\n");
    while (L<=R){
        ll M=(L+R)/2;
        if (check(M)) R=M-1;
        else L=M+1;
        //printf("%lld\n",M);
    }
    cout<<L;
}