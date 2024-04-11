#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int k,n,cnt,belong[N],son[N][2],pd[N],cf[N];
char val[N];
char s[N];
void dfs(int x){
    if(x==0)return;
    dfs(son[x][0]);
    val[++cnt]=s[x];
    belong[cnt]=x;
    dfs(son[x][1]);
}
bool solve(int x,int cot){
    if(!x)return 0;
    if(k<cot)return 0;
    if(solve(son[x][0],cot+1))cf[x]=1;
    else if(pd[x])cf[x]=1,k-=cot;
    if(cf[x])solve(son[x][1],1);
    return cf[x];
}
int main(){
    scanf("%d%d\n",&n,&k);
    cin.getline(s+1,N);
    for(int i=1;i<=n;i++)scanf("%d%d",&son[i][0],&son[i][1]);
    dfs(1);
    char last=val[n];
    for(int i=n-1;i>=1;i--){
        if(val[i]<last)pd[belong[i]]=1;
        if(last!=val[i]&&val[i-1]!=val[i])last=val[i];
    }
    solve(1,1);
    for(int i=1;i<=n;i++){
        printf("%c",val[i]);
        if(cf[belong[i]])printf("%c",val[i]);
    }
    return  0;
}