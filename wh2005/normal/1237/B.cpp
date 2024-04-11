#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,a[N],b[N],c[N];


int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    reverse(a+1,a+n+1);
    reverse(b+1,b+n+1);
    for(int i=1;i<=n;i++) c[a[i]]=i;
    for(int i=1;i<=n;i++) b[i]=c[b[i]];
    int mx=0,ans=0;
    for(int i=1;i<=n;i++){
        mx=max(mx,b[i]);
        if(b[i]<mx) ans++;
    }
    printf("%d\n",ans);
    return 0;
}