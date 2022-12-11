#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n,a[N];

int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        printf("? 1 %d\n",i);
        fflush(stdout);
        scanf("%d",a+i);
    }
    printf("? 2 3\n");
    fflush(stdout);
    scanf("%d",a+1);
    a[1]=(a[2]+a[3]-a[1])/2;
    for(int i=2;i<=n;i++) a[i]-=a[1];
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    printf("\n");
    fflush(stdout);
}