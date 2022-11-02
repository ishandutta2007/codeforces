#include<bits/stdc++.h>
using namespace std;
const int N = 209;
int T,n,a[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=(n/2);i++)
            printf("%d ",-a[n-i+1]);
        for(int i=(n/2)+1;i<=n;i++)
            printf("%d ",a[n-i+1]);
        puts("");
    }
    return 0;
}