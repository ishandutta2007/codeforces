#include <cstdio>
#include <cmath>
#include <cstdlib>
int n,x,y;
double t;
int main() {
    scanf("%d%d%d",&n,&x,&y);
    printf("%.0f",(t=ceil(n*y/100.0)-x)>0?t:0);
}