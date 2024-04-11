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
const int N=1e5+10;

int n,a[N],s[N],f[N];
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int top=0;
    FOR(i,1,n){
        int v=1;
        while (top&&a[i]>a[s[top]]) v=max(v,f[s[top--]]+1);
        if (top) f[i]=v;
        s[++top]=i;
    }
//    FOR(i,1,n) cout<<f[i]<<" \n"[i==n];
    cout<<*max_element(f+1,f+n+1);
}