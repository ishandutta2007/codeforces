#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main(){
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",3*min(a,min(b-1,c-2))+3);
    return 0;
}