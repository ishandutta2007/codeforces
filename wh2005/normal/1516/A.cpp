#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int T,n,m,a[N];


int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[n]+=m;
        for(int i=1;i<=n;i++){
            int x=min(m,a[i]);
            a[i]-=x,m-=x;
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
    }
    return 0;
}