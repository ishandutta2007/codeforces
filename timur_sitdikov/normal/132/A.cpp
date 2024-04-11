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

int inv(int v)
{
    int ans=0, i;
    for(i=0; i<8; i++)
    {
        ans=(ans<<1)|(v&1);
        v>>=1;
    }
    return ans;
}

int main()
{   
    char c[200];
    int i, j, l, prv=0, cur, tmp, tmp1;
    for(l=0; (c[l]=getchar())>=32 && c[l]<=126; l++);
    for(i=0; i<l; i++)
    {
        tmp=inv(prv);
        tmp1=inv((int)c[i]);
        cur=(tmp-tmp1+256)%256;
        printf("%d\n", cur);
        prv=c[i];
    }
}