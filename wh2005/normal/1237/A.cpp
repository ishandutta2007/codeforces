#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,a[N],b[N];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int sum=0;
    for(int i=1;i<=n;i++){
        b[i]=a[i]/2;
        sum+=b[i];
    }
    if(sum<0){
        for(int i=1;i<=n;i++)
            if(a[i]%2!=0&&a[i]>0&&sum<0) b[i]++,sum++;
    }
    if(sum>0){
        for(int i=1;i<=n;i++)
            if(a[i]%2!=0&&a[i]<0&&sum>0) b[i]--,sum--;
    }
    for(int i=1;i<=n;i++) printf("%d ",b[i]);
    puts("");
    return 0;
}