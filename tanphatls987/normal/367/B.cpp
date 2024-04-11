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
const int N=2e5+10;

int n,m,k,a[N],b[N],h[N],c[N];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,m) scanf("%d",b+i);
    sort(b+1,b+m+1);
    int m1=m;m=0;
    FOR(i,1,m1){
        b[++m]=b[i];
        int j=i;
        while (j<m1&&b[j+1]==b[j]) j++;
        c[m]=j-i+1;
        i=j;
    }
    b[m+1]=inf<<1;
    FOR(i,1,n){
        int x=lower_bound(b+1,b+m+1,a[i])-b;
        if (b[x]==a[i]) a[i]=x;
        else a[i]=m+1;
    }
    vector <int> ans;
    for(int st=1;st<=min(k,n);st++){
        for(int i=st,cE=1,cM=1;i<=n;i+=k,cE++){
            if (h[a[i]]==c[a[i]]) cM--;
            if (h[a[i]]==c[a[i]]-1) cM++;
            h[a[i]]++;
            if (cM==m+1) ans.push_back(i-(m1-1)*k);
            //printf("%d %d %d\n",i,cM,cE);
            if (cE==m1){
                int x=i-(m1-1)*k;
                //printf("%d %d %d %d\n",i,x,h[a[x]],c[a[x]]);
                if (h[a[x]]==c[a[x]]) cM--;
                if (h[a[x]]==c[a[x]]+1) cM++;
                h[a[x]]--;
                cE--;
            }
            //printf("%d %d %d\n",i,cM,cE);
        }
        for(int j=1,i=st+(n-st)/k*k;i>0&&j<m1;j++,i-=k) h[a[i]]--;
        //FOR(i,1,m+1) cout<<h[i]<<" \n"[i==m+1];
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(auto i:ans) printf("%d ",i);
}