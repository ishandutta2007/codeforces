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

int cmp(const void *c1, const void *c2)
{return *(int*)c1-*(int*)c2;}

bool cmp(int a, int b)
{return a<b;}

int main()
{   

    string s1, s2, s;
    int n, i, f1=0, f2=0;
    cin >> n >> s;
    s1=s.substr(0, n);
    s2=s.substr(n, n);
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for(i=0; i<n; i++)
    {
        if (s1[i]<=s2[i]) f1=1;
        if (s1[i]>=s2[i]) f2=1;
    }
    if (f1 && f2) printf("NO");
    else printf("YES");
}