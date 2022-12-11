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

int n,m,x,truth[N],ans[N];
char ch;
vector <int> a[2][N];
int main(){
    scanf("%d%d",&n,&m);
    int sum=0;
    FOR(i,1,n){
        scanf("\n%c%d",&ch,&x);
        a[ch=='+'][x].push_back(i);
        //printf("%c %d\n",ch,x);
        sum+=ch=='-';
    }
    FOR(sus,1,n) if (sum-a[0][sus].size()+a[1][sus].size()==m) truth[sus]=1;
    bool single=count(truth+1,truth+n+1,1)==1;
    FOR(sus,1,n)
        for(auto i:a[1][sus]) {
            if (truth[sus]) ans[i]=single?1:0;
            else ans[i]=-1;
        }
    FOR(sus,1,n)
        for(auto i:a[0][sus]){
            if (truth[sus]) ans[i]=single?-1:0;
            else ans[i]=1;
        }
    FOR(i,1,n) if (ans[i]==1) printf("Truth\n");
    else if (ans[i]==-1) printf("Lie\n");
    else printf("Not defined\n");
}