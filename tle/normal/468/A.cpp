#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <sstream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n<=3) printf("NO\n");
    else
    {
        printf("YES\n");
        if(n&1) printf("2 - 1 = 1\n1 + 3 = 4\n4 * 5 = 20\n20 + 4 = 24\n");
        else printf("1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n");
        for(int i=5+(n&1);i<=n;i+=2) printf("%d - %d = 1\n24 * 1 = 24\n",i+1,i);
    }
}