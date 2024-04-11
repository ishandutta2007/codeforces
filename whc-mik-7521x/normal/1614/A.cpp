#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,l,r,k,ans=0;
        scanf("%d%d%d%d",&n,&l,&r,&k);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int i=1;
        while(a[i]<l)i++;
        for(;i<=n&&a[i]<=r&&a[i]<=k;i++){
            k-=a[i];
            ans++;
        }
        printf("%d\n",ans);
    }
    return  0;
}