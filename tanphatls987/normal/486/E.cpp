#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")

typedef long long ll;
typedef pair<int,int> ii;

const int inf=2e9;
const int MOD=1e9+7;
const int N=1e5+10;

int a[N],n,ans[N],f[N][2],s[N];
vector <int> st[N];
void solve(){
    int top=0;
    FOR(i,1,n){
        int L=1,R=top;
        while (L<=R){
            int M=(L+R)>>1;
            if (a[i]>s[M]) L=M+1;
            else R=M-1;
        }
        f[i][0]=L;
        s[L]=a[i];
        if (L>top) top++;
    }
    int lgest=top;
    top=0;
    FORD(i,n,1){
        int L=1,R=top;
        while (L<=R){
            int M=(L+R)>>1;
            if (a[i]<s[M]) L=M+1;
            else R=M-1;
        }
        f[i][1]=L;
        s[L]=a[i];
        if (L>top) top++;
    }
    FOR(i,1,n) if (f[i][0]+f[i][1]-1<top) ans[i]=1;
    FOR(i,1,n) if (!ans[i]) st[f[i][0]].push_back(i);
    FOR(i,1,top) {
        if (st[i].size()>1) for(auto& j:st[i]) ans[j]=2;
        else if (st[i].size()==1) ans[st[i][0]]=3;
    }
    FOR(i,1,n) printf("%d",ans[i]);
}
int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    solve();
}