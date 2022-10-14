#include <bits/stdc++.h>
using namespace std;
const int N=100050;
int n,a[N];
int main(){
    scanf("%i",&n);
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    if(n<=2)return 0*printf("0");
    sort(a,a+n);
    printf("%i",min(a[n-1]-a[1],a[n-2]-a[0]));
    return 0;
}