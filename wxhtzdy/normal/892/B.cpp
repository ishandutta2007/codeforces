#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int x=n-1-a[n-1],cnt=1;
    for(int i=n-2;i>=0;i--){
        if(x>i)cnt++;
        x=min(x,i-a[i]);
    }
    printf("%i",cnt);
}