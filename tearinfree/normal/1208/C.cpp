#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

int n,ans[1000][1000];
int main() {
    scanf("%d",&n);

    int v=0;
    for(int i=0;i<n;i+=4)for(int j=0;j<n;j+=4){
        for(int a=0;a<4;a++)for(int b=0;b<4;b++) {
            ans[i+a][j+b]=v++;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) printf("%d ",ans[i][j]);
        puts("");
    }
    
    return 0;
}