#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100010];
int main()
{
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if(a[n] == 1)a[n] = 2;
    else a[n] = 1;
    sort(a+1,a+n+1);
    for(int i = 1; i <= n; i++)
        printf("%d ",a[i]);
    return 0;
}