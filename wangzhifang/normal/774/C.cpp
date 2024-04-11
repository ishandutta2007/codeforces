#include <cstdio>
using namespace std;
int main(){
    int x;
    scanf("%d",& x);
    if(x&1)
        printf("7");
    else
        printf("1");
    x>>=1;
    while(--x)
        printf("1");
}