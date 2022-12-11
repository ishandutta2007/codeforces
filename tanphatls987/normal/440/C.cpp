#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>

using namespace std;

const int maxi=100000;

int ans=0,i,j,k=0,tmp;
int64_t n,s[17]={0};
int solve(int64_t x)
{
    int tmp,i=k;
    if (x<=11) return min(x,11-x+2);
    while (s[i-1]>=x) i--;
    tmp=((x/s[i-1])*(i-1)+solve(x%s[i-1]));
    if (2*x<s[i]) return tmp;
    return min(tmp,i+solve(s[i]-x));
}
int main()
{
    scanf("%I64d",&n);
    do{k++;s[k]=10*s[k-1]+1;} while (s[k]<n);
    ans=solve(n);
    printf("%d",ans);
}