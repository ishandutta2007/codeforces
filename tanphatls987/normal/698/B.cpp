#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("B.inp","r",stdin)
#define OUTPUT freopen("B.out","w",stdout)
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
const int N=2e5+10;

int n,a[N],deg[N];
int h[N];

int s[N];
void prepare(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n) deg[a[i]]++;
}
vector <int> fixpt;
void solve(){
    int root=-1;
    for(int i=1;i<=n;i++) if (deg[i]==0){
        int st=i;
        int n1=0;
        while (!h[st]){
            h[st]=1;
            s[++n1]=st;
            st=a[st];
        }
        if (h[st]==1){
            if (st==s[n1]&&root==-1) root=st;
            else fixpt.push_back(s[n1]);
        }
        for(int j=1;j<=n1;j++) h[s[j]]=-1;
    }
    for(int i=1;i<=n;i++) if (h[i]==0){
        int st=i;
        int n1=0;
        while (!h[st]){
            h[st]=1;
            s[++n1]=st;
            st=a[st];
        }
        if (h[st]==1){
            if (st==s[n1]&&root==-1) root=st;
            else fixpt.push_back(s[n1]);
        }
        for(int j=1;j<=n1;j++) h[s[j]]=-1;
    }

    if (root==-1)
        root=fixpt.back();
    for(auto i:fixpt) a[i]=root;
    printf("%d\n",fixpt.size());
    FOR(i,1,n) printf("%d ",a[i]);
}
int main(){
//    freopen("input.inp","r",stdin);
    prepare();
    solve();
}