#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int one = n-c-e;
    if (one>b) one = b;
    n-=one;
    int two = n-e;
    if (two>d) two = d;
    n-=two;
    printf("%d %d %d\n",one,two,n);
}