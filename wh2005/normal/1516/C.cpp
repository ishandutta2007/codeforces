#include<bits/stdc++.h>
using namespace std;
const int N = 1e2+9;
const int V = 2e3+9;
int n,a[N],sum;
int f[N*V];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sum=0;
    for(int i=1;i<=n;i++) sum+=a[i];
    if(sum&1){printf("0\n");return 0;}
    sum/=2;
    f[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=sum;j>=0;j--)
            if(f[j]){if(j+a[i]<=sum) f[j+a[i]]=1;}
    }
    if(!f[sum]){printf("0\n");return 0;}
    int flag=0;
    for(int i=1;i<=n;i++) if(a[i]&1) flag=i;
    if(flag){
        printf("1\n%d\n",flag);
        return 0;
    }
    while(1){
        for(int i=1;i<=n;i++) a[i]/=2;
        for(int i=1;i<=n;i++) 
            if(a[i]&1){
                printf("1\n%d\n",i);
                return 0;
            }
    }
    return 0;
}