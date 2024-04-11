#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N],sum;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) sum^=a[i];
    if(!(n&1)&&sum){printf("NO\n");return 0;}
    if(!(n&1)) n--;
    printf("YES\n");
    printf("%d\n",n-1);
    for(int i=1;i+2<=n;i+=2) printf("%d %d %d\n",i,i+1,i+2);
    for(int i=1;i+2<=n;i+=2) printf("%d %d %d\n",i,i+1,n);
    return 0;
}