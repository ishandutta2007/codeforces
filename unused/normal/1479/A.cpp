#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int read_value(int x)
{
    if (x <= 0 || x > n) return 2e9;
    
    printf("? %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
 
void recur(int a, int b)
{
    int m = (a + b) / 2;
    int l = read_value(m - 1);
    int r = read_value(m + 1);
    int x = read_value(m);
    
    if (l > x && x < r)
    {
        printf("! %d\n", m);
        exit(0);
    }
    
    else if (l < x) recur(a, m - 1);
    else recur(m + 1, b);
}
 
int main()
{
    scanf("%d",&n);
    recur(1, n);
}