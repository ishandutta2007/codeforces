#include<bits/stdc++.h>
using namespace std;
const int N = 59;
int T,a[N],b[N],x,n;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        int flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]+b[n-i+1]>x) flag=0;
        }
        if(flag) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}