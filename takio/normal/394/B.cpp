#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[1001000];
int main(){
    int p,x,i,j;
    cin>>p>>x;
    for(i=x;i<=9;i++)
    {
        a[1]=i;
        //a[p+1]=0;
        int t=0;
        for(j=2;j<=p+1;j++){
            a[j]=a[j-1]*x+t,t=a[j]/10,a[j]%=10;
        }
//        if(i==7)for(j=p+1;j>=1;j--)
//            printf("%d",a[j]);
        if(t==0&&a[p+1]==i&&a[p]!=0){
//            cout<<i<<' ';
            for(j=p;j>=1;j--)
                printf("%d",a[j]);
            return 0;
        }
    }
    printf("Impossible");
}