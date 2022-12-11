#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ans=n;
    while (m--){
        int x,y;
        scanf("%d%d",&x,&y);
        ans=min(ans,y-x+1);
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++) printf("%d ",i%ans);
}