#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long int lint;
const lint M=1e9+7;

vector<lint>ans;
vector<lint>s;
vector<lint>c;
vector<vector<lint> >m;
lint k;

lint C(lint n,lint k){
    /*if(k>n){return 0;}
    if(n==k){return 1;}
    if(k==0){return 1;}
    return (C(n-1,k-1)+C(n-1,k))%M;*/
    return m[n][k];
}

int main(){
    scanf("%I64d",&k);
    c.resize(k);ans.resize(k);s.resize(k);
    for(lint i=0;i<k;i++){
        scanf("%I64d",&c[i]);
        s[i]=(i==0)? c[i] : s[i-1]+c[i];
    }
    m.resize(1002);
    for(lint i=1;i<1002;i++){
        m[i].resize(1002);
        for(lint j=0;j<1002;j++){
            if(j>i){m[i][j]=0;continue;}
            if(i==j){m[i][j]=1;continue;}
            if(j==0){m[i][j]=1;continue;}
            m[i][j]=m[i-1][j-1]+m[i-1][j];
            m[i][j]%=M;
        }
    }
    ans[0]=1;
    for(lint i=1;i<k;i++){
        //printf("!!!%I64d\n",C(s[i-1]+c[i]-1,c[i]-1));
        lint curr=ans[i-1]*C(s[i-1]+c[i]-1,c[i]-1)%M;
        ans[i]=curr;
    }
    printf("%I64d",ans[k-1]%M);
    return 0;
}