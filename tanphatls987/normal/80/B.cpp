#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

#define check() printf("tick\n")
using namespace std;

const int maxi=100000;

char s[10];
int n,m;
float h;
int main()
{
    scanf("%s",s);
    sscanf(s,"%d:%d",&n,&m);
    h=(n%12)*30;
    if (m) h+=float(m)/2;
    printf("%.1f %d",h,6*m);
}