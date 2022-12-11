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

int a[100];
ll n;
ll solve(){
    int top=0;
    while (n) a[++top]=(n%3),n/=3;
    int st=1;
    while (!a[st]) st++;
    a[++st]++;

    ll ans=0,cur=1;
    FOR(i,st,max(st,top)) ans+=cur*a[i],cur*=3;
    return ans;
}
int main(){
    cin>>n;
    cout<<solve();
}