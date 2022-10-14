#include<bits/stdc++.h>
using namespace std;
int n,k=1;
int main(){
    scanf("%i",&n);
    k=sqrt(n);
    int ans=k*4;
    int diff=n-(k*k);
    if(diff>=1)ans+=2;
    if(diff>k)ans+=2;
    //if(diff>k)ans++;
    printf("%i",ans);
}