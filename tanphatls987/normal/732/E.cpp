#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=2e5+10;
const ll inf=4e18;

int n,n1,m;
int a[N],b[N];

vector <int> imp[N],choice[N];


int pa[N];
int ansb[N],ansm[N];
bool comp(int x,int y){
    return b[x]<b[y];
}
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++) scanf("%d",b+i);
    for(int i=1;i<=n;i++) pa[i]=a[i];
    sort(pa+1,pa+n+1);
    n1=unique(pa+1,pa+n+1)-pa-1;
    ///
    for(int i=1;i<=n;i++){
        int idx=lower_bound(pa+1,pa+n1+1,a[i])-pa;
        imp[idx].push_back(i);
    }
    for(int i=1;i<=m;i++){
        int val=b[i];
        while (1){
            int idx=lower_bound(pa+1,pa+n1+1,val)-pa;
            if (val==pa[idx])
                choice[idx].push_back(i);
            if (val==1) break;
            val=(val+1)/2;
        }
    }
    for(int i=1;i<=n1;i++) sort(choice[i].begin(),choice[i].end(),comp);
}
void solve(){
    for(int i=n1;i>=1;i--){
        int cur=0;
        for(auto y:choice[i]) if (!ansb[y]){
            if (cur>=imp[i].size()) break;
            int x=imp[i][cur++];
            ansm[x]=y;
            ansb[y]=1;
            int val=b[y];
            while (val!=pa[i]){
                ++ansb[y];
                val=(val+1)/2;
            }
        }
    }
    int sansm=n-count(ansm+1,ansm+n+1,0);
    int sansb=0;
    for(int i=1;i<=m;i++) if (ansb[i]) ansb[i]--;
    for(int i=1;i<=m;i++) sansb+=ansb[i];
    printf("%d %d\n",sansm,sansb);
    for(int i=1;i<=m;i++) printf("%d ",ansb[i]);
    printf("\n");
    for(int i=1;i<=n;i++) printf("%d ",ansm[i]);
}

int main(){
    prepare();
    solve();
}