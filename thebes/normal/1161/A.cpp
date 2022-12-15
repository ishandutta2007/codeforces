#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, k, arr[MN], a[MN], b[MN], i, ans;

int main(){
    for(scanf("%d%d",&n,&k),i=1;i<=k;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=k;i++) a[arr[i]]++;
    for(i=1;i<=n;i++){
        if(!a[i]){
            if(i-1>0) ans++;
            ans++;
            if(i+1<=n) ans++;
        }
    }
    for(i=k;i>=1;i--){
        b[arr[i]]++;
        a[arr[i]]--;
        if(!a[arr[i]]){
            if(arr[i]+1<=n&&!b[arr[i]+1]) ans++;
            if(arr[i]-1>0&&!b[arr[i]-1]) ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}