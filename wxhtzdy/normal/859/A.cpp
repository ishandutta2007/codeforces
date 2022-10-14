#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);

    printf("%i",max(0,a[n-1]-25));
}