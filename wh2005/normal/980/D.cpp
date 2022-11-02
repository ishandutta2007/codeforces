#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e3+9;
int n,a[N],nxt[N];
int f[N][N],ans[N];
bool check(int x){
    if(x<0) return 0;
    if(x==0) return 0;
    int p=sqrt(x);
    if(p*p==x) return 1;
    return 0;
}
signed main(){
    memset(ans,0,sizeof(ans));
    memset(nxt,-1,sizeof(nxt));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]==0) nxt[i]=i;
        else for(int j=i+1;j<=n;j++)
            if(check(a[j]*a[i])){nxt[i]=j;break;}
    }
    ans[1]=n;
    for(int i=1;i<=n;i++) f[i][i]=(a[i]!=0);
    for(int len=2;len<=n;len++){
        for(int i=1;i<=n-len+1;i++){
            int j=i+len-1;
            if(nxt[i]==-1&&a[i]!=0) f[i][j]=f[i+1][j]+1;
            else f[i][j]=f[i+1][j]+(nxt[i]>j);
            if(!f[i][j]) ans[1]++;
            else ans[f[i][j]]+=1;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%lld ",ans[i]);
    return 0;
}