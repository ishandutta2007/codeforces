#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
int a[N],z,n;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&z);
        int ans=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans=max(ans,z|a[i]);
        printf("%d\n",ans);
    }
    return  0;
}