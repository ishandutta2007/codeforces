#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int A,B;
    scanf("%d%d",&A,&B);
    for (int i=B+1;i<=A+B+1;i++) printf("%d ",i);
    for (int i=B;i>0;i--) printf("%d ",i);

    return 0;
}