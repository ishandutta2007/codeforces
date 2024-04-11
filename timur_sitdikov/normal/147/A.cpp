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

int is_good(char c)
{return c>='A' && c<='Z' || c>='a' && c<='z';}

int is_sign(char c)
{return c=='.' || c==',' || c=='!' || c=='?';}

int main()
{   
    char c, c1='a';
    int f=0;
    for(; (c=getchar())!=EOF; )
    {
        if (is_good(c) && !is_good(c1)) 
        {
            if (f) putchar(' ');
        }
        if (is_good(c)) f=1;
        if (c!=' ') putchar(c);
        c1=c;
    }
}