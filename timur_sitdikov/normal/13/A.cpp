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

int gcd(int a, int b)
{return b? gcd(b, a%b): a;}

int main()
{   
    int ans=0, a, i, j, g;
    scanf("%d", &a);
    for(i=2; i<a; i++)
    {
        j=a;
        while(j)
        {
            ans+=j%i;
            j/=i;
        }
    }
    g=gcd(ans, a-2);
    printf("%d/%d", ans/g, (a-2)/g);
}