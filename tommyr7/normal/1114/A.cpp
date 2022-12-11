#include <bits/stdc++.h>
using namespace std;
int x,y,z,a,b,c;
int main()
{
    scanf("%d%d%d",&x,&y,&z);
    scanf("%d%d%d",&a,&b,&c);
    bool flag=true;
    if (a<x) flag=false;
    a-=x;
    if (a+b<y) flag=false;
    b-=y;
    if (a+b+c<z) flag=false;
    if (flag) printf("YES\n"); else printf("NO\n");
    return 0;
}