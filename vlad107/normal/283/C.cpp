#include <stdio.h>
#include <memory.h>
#include <iostream>
#define ll long long
#define N 500500
#define B 1000000007
ll u[N];
int f[N],e[N],s[N],n,q,t,a[N],r[N],w[N];
bool ex=false;
ll dfs(int x){
    w[x]=1;
    if (ex)return 0;
    if (x<0)return 0;else{
        if (r[x]){
            ex=true;
            return 0;
        }
        r[x]=1;
        u[x]=dfs(e[x])+a[x];
        r[x]=0;
        return u[x];
    }
}
int main(){
    scanf("%d%d%d",&n,&q,&t);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    memset(f,0,sizeof(a));
    memset(e,-1,sizeof(e));
    for (int i=0;i<q;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        e[b]=a;f[a]=1;
    }
    for (int i=0;i<n;i++)
        if (!f[i])dfs(i);
    for (int i=0;i<n;i++)
        if (!w[i]){
            ex=true;
            break;
        }
    if (ex){
        puts("0");
        return 0;
    }
    s[0]=1;
    for (int i=0;i<n;i++){
        if (f[i]){
            for (int j=t;j>=0;j--)
                if (j>=u[i])s[j]=s[j-u[i]];else s[j]=0;
        }
        for (int j=u[i];j<=t;j++){
            s[j]+=s[j-u[i]];
            if (s[j]>=B)s[j]-=B;
        }
    }
    printf("%d\n",s[t]);
}