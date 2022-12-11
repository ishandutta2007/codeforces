#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[10000];
int d[4001][4001],dp[2][4001],n;
int get(int x,int y){
    return d[y][y]+d[x-1][x-1]-d[x-1][y]-d[y][x-1];
}
bool fresh(int& x,int v){
    if(x>v){
        x=v;
        return 1;
    }
    return 0;
}
void go(int d1[],int d2[],int l1,int r1,int l2,int r2){
    int m1=(l1+r1)/2,pos,i,mi=1000000000;
    for(i=l2;i<=r2&&i<m1;i++){
        if(fresh(mi,d1[i]+get(i+1,m1)))pos=i;
    }
    d2[m1]=mi;
    if(l1<m1)go(d1,d2,l1,m1-1,l2,pos);
    if(m1<r1)go(d1,d2,m1+1,r1,pos,r2);
}
int main(){
    int i,j,k;
    scanf("%d%d",&n,&k);
    for(i=1;i<=n;i++){
        for(j=0;j<n;j++)
        {
            scanf("%d", &d[i][j+1]);
            d[i][j+1] += d[i][j];
        }    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)d[i][j]+=d[i-1][j];
    int now=0;
    for(i=1;i<=n;i++)dp[now][i]=get(1,i);
    for(i=1;i<k;i++,now^=1){
        go(dp[now],dp[now^1],i+1,n,i,n-1);
    }
    printf("%d\n",dp[now][n]/2);
    return 0;
}