#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x=0,y=1e9+7,ans1=1,ans2=1;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int u;
            scanf("%d",&u);
            if(u>x)x=u,ans1=i;
            if(u<y)y=u,ans2=i;
        }
        printf("%d %d\n",ans1,ans2);
    }
    return  0;
}