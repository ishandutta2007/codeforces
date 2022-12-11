#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("D.inp","r",stdin)
#define OUTPUT freopen("D.out","w",stdout)
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
const int N=1e3+10;

int n,a[N],s[N];
map <int,int> h;
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) {
        scanf("%d",a+i);
        h[a[i]]++;
    }
}
int solve(){
    int ans=h[0];
    FOR(i,1,n)
        FOR(j,1,n) if (i!=j&&(a[i]||a[j])){
            int top=2;
            s[1]=a[i];
            s[2]=a[j];
            FOR(k,1,2) h[s[k]]--;
            while (1){
                s[top+1]=s[top-1]+s[top];
                if (h[s[top+1]]) {
                    top++;
                    h[s[top]]--;
                }else break;
            }
            ans=max(ans,top);
            FOR(k,1,top) h[s[k]]++;
        }
    return ans;
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    cout<<solve();
}