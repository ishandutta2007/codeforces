#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int is_gl(char c)
{return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y';}

int is_b_lt(char c)
{return c>='A' && c<='Z';}

int is_sm_lt(char c)
{return c>='a' && c<='z';}

int main()
{   
  
    char c;
    for(; (c=getchar())!=EOF;)
    {
        if (is_gl(c)) continue;
        if (is_b_lt(c)) {putchar('.'); putchar(c-'A'+'a'); continue;}
        if (is_sm_lt(c)) {putchar('.'); putchar(c); continue;}
        putchar(c);
    }
}