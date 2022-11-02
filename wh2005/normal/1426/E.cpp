#include<bits/stdc++.h>
using namespace std;
int n,a[4],b[4];

int main(){
    scanf("%d",&n);
    scanf("%d%d%d",&a[1],&a[2],&a[3]);
    scanf("%d%d%d",&b[1],&b[2],&b[3]);
    int mn=0,mx=0;
    if(b[3]+b[1]<a[1]) mn+=a[1]-b[3]-b[1];
    if(b[1]+b[2]<a[2]) mn+=a[2]-b[1]-b[2];
    if(b[2]+b[3]<a[3]) mn+=a[3]-b[2]-b[3];
    mx+=min(a[1],b[2])+min(a[2],b[3])+min(a[3],b[1]);
    printf("%d %d\n",mn,mx);
    return 0;
}