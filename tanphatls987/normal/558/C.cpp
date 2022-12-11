#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("C.inp","r",stdin)
#define OUTPUT freopen("C.out","w",stdout)
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
const int N=1e5+5;

int h[N],n,x,c[N];
ii s[200];
vector <ii> v[N];
bool comp(ii a,ii b){
    if (a.X==b.X) return a.Y<b.Y;
    return a.X<b.X;
}
void prepare(){
    REP(i,1,N){
        int top=0;
        for(int j=0,tmp=i;tmp;j++,tmp>>=1)
            for(int k=0,tmp1=tmp;tmp1<N;k++,tmp1<<=1) s[++top]=ii(tmp1,j+k);
        sort(s+1,s+top+1,comp);
        FOR(j,1,top) {
            v[i].push_back(s[j]);
//            printf("%d %d %d\n",i,s[j].X,s[j].Y);
            while (j<top&&s[j+1].X==s[j].X) j++;
        }
    }
}
int main(){
//    OUTPUT;
    prepare();
    scanf("%d",&n);
    FOR(i,1,n){
        scanf("%d",&x);
        for(auto j:v[x]){
            c[j.X]+=j.Y;
            h[j.X]++;
        }
    }
    int ans=inf;
//    REP(i,1,N) printf("%d %d %d\n",i,c[i],h[i]);
    REP(i,1,N) if (h[i]==n) ans=min(ans,c[i]);
    cout<<ans;
}