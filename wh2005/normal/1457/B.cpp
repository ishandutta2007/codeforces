#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int T,n,m,a[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);int mx=0,ans=n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx=max(a[i],mx);
        for(int i=1;i<=mx;i++){
            int area=0;
            for(int j=1;j<=n;j++){
                if(a[j]!=i) j=j+m-1,area++; 
            }
            ans=min(area,ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}