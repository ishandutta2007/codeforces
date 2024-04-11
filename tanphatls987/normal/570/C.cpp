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
const int N=3e5+10;

char s[N],ch;
int a[N],n,m,x,block=0,c=0;
void modified(int x,int v){
    c+=v;
    if (a[x-1]&&a[x+1]) block-=v;
    else if (!a[x-1]&&!a[x+1]) block+=v;
    a[x]+=v;
}
int main(){
    scanf("%d%d\n%s",&n,&m,s);
//    printf("%d %d %s\n",n,m,s);
    FOR(i,1,n) a[i]=(s[i-1]=='.');
    c=count(a+1,a+n+1,1);
//    FOR(i,1,n) cout<<a[i]<<" \n"[i==n];
    block=0;
    FOR(i,1,n) if (a[i]){
        block++;
        while (a[i+1]) i++;
    }
//    cout<<c<<" "<<block<<'\n';
    while (m--){
        scanf("%d %c",&x,&ch);
        modified(x,(ch=='.')-a[x]);
        printf("%d\n",c-block);
    }
}