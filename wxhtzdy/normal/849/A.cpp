#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    if(n%2==1&&a[0]%2==1&&a[n-1]%2==1)printf("Yes\n");
    else printf("No\n");
    return 0;
}