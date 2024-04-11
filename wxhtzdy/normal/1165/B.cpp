#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    int nxt=1;
    for(int i=0;i<n;i++){
        if(a[i]>=nxt)nxt++;
    }
    printf("%i",nxt-1);
}