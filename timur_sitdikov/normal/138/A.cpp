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

int k;
string st[10005];

int is_good(char c)
{
    if  (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return 1;
    return 0;
}

int rfm(string s1, string s2)
{
    int i1, i2, l1, l2, ans=0;
    l1=s1.length(); l2=s2.length();
    for(i1=l1-1, i2=l2-1; i1>=0 && i2>=0; )
    {
        if (s1[i1]!=s2[i2]) return 0;
        if (is_good(s1[i1])) ans++;
        if (ans==k) return 1;
        i1--; i2--;
    }
    return 0;
}

int main()
{   
    int i, f1, f2, f3, n;
    f1=f2=f3=1;
    scanf("%d %d", &n, &k);
    for(i=0; i<4*n; i++)
        cin >> st[i];
    for(i=0; i<4*n; i+=4)
    {
        if (!rfm(st[i], st[i+2]) || !rfm(st[i+1], st[i+3]))
            f1=0;
        if (!rfm(st[i], st[i+1]) || !rfm(st[i+2], st[i+3])) 
            f2=0;
        if (!rfm(st[i], st[i+3]) || !rfm(st[i+2], st[i+1])) 
            f3=0;
    }
    if (f1 && f2 && f3) {printf("aaaa"); return 0;}
    if (f1) {printf("abab"); return 0;}
    if (f2) {printf("aabb"); return 0;}
    if (f3) {printf("abba"); return 0;}
    printf("NO");
}