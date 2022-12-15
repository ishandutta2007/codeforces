#include <bits/stdc++.h>
using namespace std;

int sm, n, i;

int main(){
    for(scanf("%d",&n),i=2;i<n;i++)
        sm += i*(i+1);
    printf("%d\n",sm);
    return 0;
}