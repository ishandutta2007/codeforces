#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{   

    long long n, good, ans, all, i, j, num[10];
    scanf("%I64d", &n);
    for(i=1, good=0; i<=n; i++)
        for(j=1; j*i<=n; j++)
        {
            good++;
        }
    all=0;
    for(i=0; i<9; i++) num[i]=0;
    for(i=1; i<=n; i++)
        num[i%9]++;
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
        {
            all+=num[i]*num[j]*num[(i*j)%9];
        }
    ans=all-good;
    printf("%I64d", ans);   
}