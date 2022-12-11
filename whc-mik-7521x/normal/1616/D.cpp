#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int t,n,x,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        scanf("%d",&x);
        for(int i=1;i<=n;i++)a[i]-=x;
        int cnt=0;
        a[n+1]=1e9;
        for(int i=1;i<n;i++){
            if(a[i]+a[i+1]<0)cnt++,i+=1;
            else if(a[i]+a[i+1]+a[i+2]<0)cnt++,i+=2;
        }
        printf("%d\n",n-cnt);
    }
    return  0;
}