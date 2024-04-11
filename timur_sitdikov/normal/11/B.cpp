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
    int s, i, n;
    scanf("%d", &n);
    if (n<0) n=-n;
    for(s=i=0; s<n || (s-n)&1; )
    {
        i++;
        s+=i;
    }
    printf("%d", i);
}