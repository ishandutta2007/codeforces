#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("b.inp","r",stdin)
#define OUTPUT freopen("b.out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=2e5+10;

int n,m,x,w,s[N],b[N];
ii a[N];
void add(int x,int v){
    while (x<=m){
        b[x]=max(b[x],v);
        x+=x&-x;
    }
}
int get(int x){
    int tmp=0;
    while (x){
        tmp=max(tmp,b[x]);
        x-=x&-x;
    }
    return tmp;
}
int main(){
    scanf("%d",&n);
    //int top=0;
    FOR(i,1,n) {
        scanf("%d%d",&a[i].X,&a[i].Y);
        s[i]=a[i].X+a[i].Y;
    }
    sort(a+1,a+n+1);
    sort(s+1,s+n+1);
    m=unique(s+1,s+n+1)-s-1;
    FOR(i,1,n){
        //scanf("%d%d",&a[i].X,&a[i].Y);
        int x=a[i].X-a[i].Y;
        int idx=upper_bound(s+1,s+m+1,x)-s-1,ans=get(idx)+1;
        add(lower_bound(s+1,s+m+1,a[i].X+a[i].Y)-s,ans);
    }
    cout<<get(m);
}