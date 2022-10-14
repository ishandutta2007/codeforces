#include<bits/stdc++.h>
using namespace std;
int n,a[150],cnt=0;
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]),cnt+=a[i]%2;
    for(int i=0;i<n;i++){
        if(cnt==1&&a[i]%2==1){printf("%i",i+1);return 0;}
        if(cnt==n-1&&a[i]%2==0){printf("%i",i+1);return 0;}
    }
}