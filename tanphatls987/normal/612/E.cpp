#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("E.inp","r",stdin)
#define OUTPUT freopen("E.out","w",stdout)
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
const int N=1e6+10;

int n,p[N],ans[N],h[N],pos[N],s[N];
vector <int> spe[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,n) pos[p[i]]=i;
}
void solve(){
    FOR(i,1,n) if (!h[i]){
        int top=0,x=i;
        while (!h[x]){
            h[x]=1;
            s[++top]=pos[x];
            x=p[x];
        }
        if (top%2==0) {
            spe[top/2].push_back(s[1]);
            continue;
        }
        if (top==1){
            ans[i]=i;
            continue;
        }
        int m1=(top+1)/2+1;
        ans[s[m1]]=p[s[1]];
        int cur=1,last=m1;
        while (cur!=m1){
            ans[s[cur]]=s[last];
            swap(cur,last);
            cur--;
            if (!cur) cur=top;
        }
    }
//    FOR(i,1,n) cout<<ans[i]<<" \n"[i==n];
    FOR(pha,1,n){
        if (spe[pha].size()&1){
            printf("-1");
            return;
        }
        int n1=spe[pha].size();
        for(int i=0;i<n1;i+=2){
            int last=spe[pha][i],cur=spe[pha][i+1];
            ans[last]=p[cur];
            while (!ans[cur]){
//                cout<<cur<<" "<<last<<'\n';
                ans[cur]=last;
                swap(cur,last);
                cur=pos[cur];
            }
        }
    }
    FOR(i,1,n) printf("%d ",ans[i]);
}
int main(){
    prepare();
    solve();
}