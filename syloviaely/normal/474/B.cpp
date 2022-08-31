#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,pd[1010000],pre;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int k1; scanf("%d",&k1);
        for (int j=pre+1;j<=pre+k1;j++) pd[j]=i;
        pre+=k1;
    }
    scanf("%d",&n);
    for (;n;n--){
        int k1; scanf("%d",&k1); printf("%d\n",pd[k1]);
    }
    return 0;
}