#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e6+6;
int n, m, i, j, x, rnk[MN], ds[MN];
vi arr[MN], a, b, c, d, ans[MN];
pii ord[MN];
bool cmp(pii i,pii j){return arr[i.first][i.second]<arr[j.first][j.second];}
int fnd(int x){return ds[x]=x==ds[x]?x:fnd(ds[x]);}

int main(){
    for(scanf("%d%d",&n,&m),i=1;i<=n;i++){
        arr[i].pb(0);
        ans[i].resize(m+1);
        for(j=1;j<=m;j++){
            scanf("%d",&x);
            arr[i].pb(x);
            ord[(i-1)*m+j]={i,j};
        }
    }
    a.resize(MN);
    b.resize(MN);
    c.resize(MN);
    d.resize(MN);
    for(i=1;i<=n*m;i++) ds[i]=i;
    sort(ord+1,ord+n*m+1,cmp);
    for(i=1;i<=n*m;){
        for(j=i;j<=n*m&&arr[ord[j].first][ord[j].second]==arr[ord[i].first][ord[i].second];j++){
            int id = (ord[j].first-1)*m+ord[j].second;
            rnk[id] = max(rnk[id], a[ord[j].first]+1);
            rnk[id] = max(rnk[id], b[ord[j].second]+1);
            if(c[ord[j].first]){
                if(fnd(id)!=fnd(c[ord[j].first])){
                    int oo = fnd(c[ord[j].first]);
                    rnk[oo] = max(rnk[oo], rnk[fnd(id)]);
                    ds[fnd(id)] = oo;
                }
            }
            if(d[ord[j].second]){
                if(fnd(id)!=fnd(d[ord[j].second])){
                    int oo = fnd(d[ord[j].second]);
                    rnk[oo] = max(rnk[oo], rnk[fnd(id)]);
                    ds[fnd(id)] = oo;
                }
            }
            c[ord[j].first]=id;
            d[ord[j].second]=id;
        }
        for(;i<j;i++){
            int id = (ord[i].first-1)*m+ord[i].second;
            int r = rnk[fnd(id)];
            ans[ord[i].first][ord[i].second]=r;
            a[ord[i].first]=b[ord[i].second]=r;
            c[ord[i].first]=0;
            d[ord[i].second]=0;
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=m;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}