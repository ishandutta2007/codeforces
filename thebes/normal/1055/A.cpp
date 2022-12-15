#include <bits/stdc++.h>
#define sq(x) ((x)*(x))
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

const int MN = 1005;
int vis[MN], wew[MN], vis2[MN], i, x, n, s;

int main(){
    for(scanf("%d%d",&n,&s),i=1;i<=n;i++){
        scanf("%d",&x);
        if(x) vis[i] = 1;
    }
    for(i=1;i<=n;i++){
        scanf("%d",&x);
        if(x) wew[i] = 1;
    }
    if(!vis[1]) printf("NO\n");
    else{
        for(i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(wew[j]&&wew[i]&&vis[i]) vis2[j]=1;
                else if(vis[j]) vis2[j]=1;
            }
        }
        printf("%s\n",vis2[s]?"YES":"NO");
    }
    return 0;
}