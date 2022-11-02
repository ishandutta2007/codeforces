#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int n,m,pre[N],lst[N];
char s[N],t[N];

int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s",s,t);
    for(int i=n;i>=1;i--) s[i]=s[i-1];
    for(int j=m;j>=1;j--) t[j]=t[j-1];
    int i=1;
    for(int j=1;j<=m;j++){
        while(i<=n&&t[j]!=s[i]) i++;
        pre[j]=i;i++;
    }
    i=n;
    for(int j=m;j>=1;j--){
        while(i>=1&&t[j]!=s[i]) i--;
        lst[j]=i;i--;
    }
    int ans=1;
    for(int j=1;j<m;j++) ans=max(ans,lst[j+1]-pre[j]);
    printf("%d\n",ans);
    return 0;
}