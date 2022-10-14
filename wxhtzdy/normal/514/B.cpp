#include<bits/stdc++.h>
using namespace std;
int n,x,y,a[1005],b[1005];
bool was[1005];
int main(){
    scanf("%i%i%i",&n,&x,&y);
    for(int i=0;i<n;i++)scanf("%i%i",&a[i],&b[i]);
    for(int i=0;i<n;i++)was[i]=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(was[i])continue;
        cnt++;
        for(int j=i+1;j<n;j++){
            if((a[i]-x)*(b[j]-y)==(a[j]-x)*(b[i]-y))was[j]=1;
        }
    }
    printf("%i",cnt);
}