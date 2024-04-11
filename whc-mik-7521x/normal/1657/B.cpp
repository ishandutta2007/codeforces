#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],t,n,x,y,b;
long long sum=0;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d",&n,&b,&x,&y);
        sum=0;
        for(int i=1;i<=n;i++){
            if(a[i-1]+x>b)a[i]=a[i-1]-y;
            else a[i]=a[i-1]+x;
            sum+=a[i];
        }
        printf("%lld\n",sum);
    }
    return  0;
}