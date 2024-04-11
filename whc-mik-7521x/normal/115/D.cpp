#include<bits/stdc++.h>
using namespace std;
const int N=2e3+50,mod=1e6+3;
char s[N];
int a[N],dp1[N][N],dp2[N][N],n,ct;
void add(int &x,int y){
    x=x+y>=mod?x+y-mod:x+y;
}
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        if(i!=1&&isdigit(s[i])&&isdigit(s[i-1]))continue;
        if(s[i]=='+'||s[i]=='-')a[++ct]=1;
        if(s[i]=='*'||s[i]=='/')a[++ct]=2;
        if(isdigit(s[i]))a[++ct]=0;
    }
    if(ct==1&&a[ct]==0)return puts("1"),0;
    dp1[1][0]=1;
    for(int i=1;i<=ct+1;i++){
        for(int o=0;o<N;o++){
            if(a[i]==1)add(dp1[i+1][o+1],dp1[i][o]);
            if(a[i]==0)add(dp1[i+2][o+1],dp1[i][o]),add(dp2[i+1][o-1],o?dp1[i][o]:0);
        }
        for(int o=N-1;o>=0;o--){
            add(dp1[i+1][o+1],dp2[i][o]);
            if(o)add(dp2[i][o-1],dp2[i][o]);
        }
    }
    printf("%d",dp2[ct+1][0]);
    return  0;
}