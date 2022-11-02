#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,a[N],b[N<<1];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=0;
    for(int i=1;i<=n;i++){
        int x=a[i];
        if(!b[x]) b[x]=1,ans++;
        for(int j=i+1;j<=n;j++){
            x|=a[j];
            if(!b[x]) b[x]=1,ans++;
            if(a[j]==(a[i]|a[j])){
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}