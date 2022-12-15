#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

const int MN = 105, MM = 1e6+6;
int dist[MN][MN], arr[MM], n, m, i, j, k, x, d;
vi ans;

int main(){
    for(scanf("%d",&n),i=1;i<=n;i++){
        for(getchar(),j=1;j<=n;j++){
            dist[i][j]=getchar()-'0';
            if(i!=j&&!dist[i][j]) dist[i][j]=1<<29;
        }
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(scanf("%d",&m),i=1;i<=m;i++)
        scanf("%d",&arr[i]);
    ans.pb(arr[1]); x = arr[1];
    d = dist[arr[1]][arr[2]];
    for(i=3;i<=m;i++){
        d += dist[arr[i-1]][arr[i]];
        if(d>dist[x][arr[i]]){
            ans.pb(arr[i-1]);
            x = arr[i-1];
            d = dist[arr[i-1]][arr[i]];
        }
    }
    ans.pb(arr[m]);
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d ",v);
    printf("\n");
    return 0;
}