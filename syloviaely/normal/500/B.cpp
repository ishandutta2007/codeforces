#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[400][400],n,x[400],pd[400],s[400],y[400],ans[400],len;
char ch[400];
void dfs(int k){
    pd[k]=1; s[++len]=k; y[len]=x[k];
    for (int i=1;i<=n;i++)
        if (A[k][i]==1&&pd[i]==0) dfs(i);
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&x[i]);
    for (int i=1;i<=n;i++){
        scanf("%s",ch+1);
        for (int j=1;j<=n;j++) A[i][j]=ch[j]-'0';
    }
    for (int i=1;i<=n;i++)
        if (pd[i]==0){
            len=0; dfs(i); sort(s+1,s+len+1); sort(y+1,y+len+1);
            for (int j=1;j<=len;j++) ans[s[j]]=y[j];
        }
    for (int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<endl;
    return 0;
}