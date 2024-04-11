#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+9;
char s[N];int n,a[N];ll f[N][2];

int main(){
    scanf("%s",s);n=strlen(s);
    for(int i=n;i>=1;i--) s[i]=s[i-1];
    for(int i=1;i<=n;i++) a[i]=s[i]-'A';
    memset(f,0,sizeof(f));
    a[0]=a[n];f[0][0]=1;ll ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0&&a[i-1]==0){
            f[i][0]=f[i-1][0]+f[i-1][1];
        }
        if(a[i]==0&&a[i-1]==1){
            f[i][0]=f[i-1][1];
            f[i][1]=f[i-1][0];
        }
        if(a[i]==1&&a[i-1]==0){
            f[i][0]=f[i-1][0]+f[i-1][1];
            f[i][1]=f[i-1][1];
        }
        if(a[i]==1&&a[i-1]==1){
            f[i][0]=f[i-1][1];
            f[i][1]=f[i-1][1];
        }
    }
    ans+=f[n][0];
    memset(f,0,sizeof(f));f[0][1]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==0&&a[i-1]==0){
            f[i][0]=f[i-1][0]+f[i-1][1];
        }
        if(a[i]==0&&a[i-1]==1){
            f[i][0]=f[i-1][1];
            f[i][1]=f[i-1][0];
        }
        if(a[i]==1&&a[i-1]==0){
            f[i][0]=f[i-1][0]+f[i-1][1];
            f[i][1]=f[i-1][1];
        }
        if(a[i]==1&&a[i-1]==1){
            f[i][0]=f[i-1][1];
            f[i][1]=f[i-1][1];
        }
    }
    ans+=f[n][1];
    printf("%lld\n",ans);
    return 0;
}