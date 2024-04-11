#include<bits/stdc++.h>
using namespace std;
long long n,m,a[55][55],col[55][2],row[55][2],sol=0;
int main(){
    scanf("%i%i",&n,&m);
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%i",&a[i][j]);
    for(int i=0;i<n;i++)col[i][0]=0,col[i][1]=0;
    for(int i=0;i<m;i++)row[i][0]=0,row[i][1]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            col[i][a[i][j]]++;
            row[j][a[i][j]]++;
        }
    }
    for(int i=0;i<n;i++){
        sol+=(long long)pow(2,col[i][0])-1;
        sol+=(long long)pow(2,col[i][1])-1;
    }
    for(int j=0;j<m;j++){
        sol+=(long long)pow(2,row[j][0])-1;
        sol+=(long long)pow(2,row[j][1])-1;
    }
    printf("%lld",(long long)sol-(long long)n*m);
}