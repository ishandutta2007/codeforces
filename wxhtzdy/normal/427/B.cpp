#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,c;
    scanf("%i %i %i",&n,&t,&c);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int L[n];
    for(int i=0;i<n;i++){
        if(a[i]>t)L[i]=i;
        else{
            if(i==0)L[i]=-1;
            else L[i]=L[i-1];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        int sz=i-L[i];
        if(sz>=c)ans++;
    }
    printf("%i",ans);
    return 0;
}