#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int a[10];
int main(){
    int n;
    scanf("%d",&n);
    a[1]=a[7]=a[9]=1;
    if((a[n%10]||n>9&&n<30||a[n/10])&&n!=12)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}