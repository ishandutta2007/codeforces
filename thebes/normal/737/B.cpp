#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;

#define pb push_back

const int MN = 2e5+5;
int n, a, b, k, i, p[MN], g[MN], arr[MN];
vi ans;

int main(){
    scanf("%d%d%d%d ",&n,&a,&b,&k);
    for(i=1;i<=n;i++) arr[i]=getchar()=='1';
    for(i=1;i<=n;i++) g[i]=g[i-1]+arr[i];
    for(i=1;i<=n;i++){
        if(i>=b){
            int ok = g[i]-g[i-b];
            if(!ok) p[i]=p[i-b]+1;
        }
        p[i]=max(p[i],p[i-1]);
    }
    for(i=n;i>=1;i--){
        if(n-i+1>=b){
            int ok = g[i+b-1]-g[i-1];
            if(!ok&&(ans.empty()||ans.back()>=i+b)){
                if(p[i-1]>=a-1) ans.pb(i);
            }
        }
    }
    printf("%d\n",ans.size());
    for(auto v : ans) printf("%d ",v);
    printf("\n");
    return 0;
}