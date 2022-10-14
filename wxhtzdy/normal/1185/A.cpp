#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[3],d;
    scanf("%i %i %i %i",&a[0],&a[1],&a[2],&d);
    sort(a,a+3);
    printf("%i",max(0,d-(a[1]-a[0]))+max(0,d-(a[2]-a[1])));
    return 0;
}