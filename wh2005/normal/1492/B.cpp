#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+9; 
int T,n,a[N],p[N];

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n==1){printf("1\n");continue;}
        for(int i=1;i<=n;i++) p[a[i]]=i;
        int ld=n+1;
        for(int i=n;i>=1;i--){
            if(p[i]>=ld) continue;
            for(int j=p[i];j<ld;j++) printf("%d ",a[j]);
            ld=p[i];
        }
        puts("");
    }
    return 0;
}