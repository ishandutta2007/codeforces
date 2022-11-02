#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,a[N],cnt;
int gcd(int x,int y){if(!y) return x;return gcd(y,x%y);}

int main(){
    scanf("%d",&n);cnt=0;
    for(int i=1;i<n;i++){if(gcd(i,n)==1) a[++cnt]=i;}
    int prod=1;
    for(int i=1;i<=cnt;i++) prod=1ll*prod*a[i]%n;
    if(prod>1){
        printf("%d\n",cnt-1);
        for(int i=1;i<=cnt;i++) if(a[i]!=prod) printf("%d ",a[i]);
        puts("");
    }
    else{
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}