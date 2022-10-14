#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    int a,b,c;
    scanf("%i%i%i",&a,&b,&c);
    int a1=a*b*c,a2=a*(b+c),a3=(a+b)*c,a4=a+b+c;
    printf("%i",max(a1,max(a2,max(a3,a4))));
}