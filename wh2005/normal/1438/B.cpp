#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+9;
int t,n,a[N];

int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);int flag=0;
        for(int i=1;i<n;i++)
            if(a[i]==a[i+1]) flag=1;
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}