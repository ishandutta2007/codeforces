#include<cstdio>
using namespace std;

int n;

int main(){
    scanf("%d", &n);
    if(n&1){printf("black");}
    else{printf("white\n1 2");}
    return 0;
}