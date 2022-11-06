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

int ex(int a, int b, int c)
{if (a==0 && b==0 && c!=0) return 1; else return 0;}

int all(int a, int b, int c)
{if (a==0 && b==0 && c==0) return 1; else return 0;}

void norm(int *a, int *b, int *c)
{
    int g;
    if (!(*b))
    {
        g=gcd(abs(*a), abs(*c));
        *a/=g; *c/=g;
    }
    else if (!(*a))
    {
        g=gcd(abs(*b), abs(*c));
        *b/=g; *c/=g;
    }
    else
    {
        g=gcd(abs(*a), abs(*b));
        g=gcd(g, abs(*c));
        *a/=g; *b/=g; *c/=g;
    }
    if (*a<0) {*a=-*a; *b=-*b; *c=-*c;}
    if (*a==0 && *b<0) {*a=-*a; *b=-*b; *c=-*c;}
}

int main()
{   

    int a1, b1, c1, a2, b2, c2;
    scanf("%d %d %d %d %d %d", &a1, &b1, &c1, &a2, &b2, &c2);
    if (ex(a1, b1, c1) || ex(a2, b2, c2)) {printf("0"); return 0;}
    if (all(a1, b1, c1) || all(a2, b2, c2)) {printf("-1"); return 0;}
    if (a1*b2!=a2*b1) {printf("1"); return 0;} 
    norm(&a1, &b1, &c1); norm(&a2, &b2, &c2);
    if (a1==a2 && b1==b2 && c1==c2) {printf("-1"); return 0;}
    printf("0");
}