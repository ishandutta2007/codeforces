#include<bits/stdc++.h>
using namespace std;
const int N=500;
int t,n,m,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%1d",&b[i]);
        int pd=1;
        for(int i=0;i<m-1;i++)if(a[n-i]!=b[m-i])pd=0;
        int ck=0;
        for(int i=1;i<=n-m+1;i++)if(a[i]==b[1])ck=1;
        puts(pd&&ck?"YES":"NO");
    }
    return 0;
}