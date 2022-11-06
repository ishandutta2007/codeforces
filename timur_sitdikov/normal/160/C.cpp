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

bool cmp(int a, int b)
{return a<b;}

int main()
{   
    long long m[100005], n, k, i, a, b, c, ind2;
    scanf("%I64d %I64d", &n, &k);
    k--;
    for(i=0; i<n; i++)
        scanf("%I64d", &m[i]);
    sort(m, m+n);
    for(i=k/n; i>=0 && m[i]==m[k/n]; i--);
    a=i+1;
    for(i=k/n; i<n && m[i]==m[k/n]; i++);
    b=i;
    c=b-a;
    ind2=(k-a*n)/c;
    printf("%I64d %I64d", m[k/n], m[ind2]);
}