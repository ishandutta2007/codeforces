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

long long m[200005];
vector <long long> ans;

int main()
{   

    long long n, i, s=0, sz;
    scanf("%I64d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%I64d", &m[i]);
        s+=m[i];
    }
    for(i=0; i<n; i++)
        if ((n-1)*m[i]==s-m[i])
            ans.push_back(i+1);
    sz=ans.size();
    printf("%I64d\n", sz);
    for(i=0; i<sz; i++)
        printf("%I64d ", ans[i]);

}