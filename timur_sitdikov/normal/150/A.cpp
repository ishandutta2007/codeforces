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
    long long n, n1,  i, j, sz, f=0, ans=1;
    scanf("%I64d", &n);
    n1=n;
    for(i=2; i*i<=n; i++)
        if (!(n%i))
        {
            while(!(n%i))
            {
                f++;
                ans*=i;
                n/=i;
                if (f==2) break;
            }
            if (f==2) break;
        }
    if (f==2 && n!=1) {printf("1 %I64d", ans);return 0;}
    if (f) printf("2");
    else printf("1 0");


}