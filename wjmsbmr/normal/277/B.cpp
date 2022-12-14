#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    if(n>=5&&m==3)
    {
        puts("-1");
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        printf("%d %d\n",(i+1),(i+1)*(i+1));
    }
    for(int i=0;i<n-m;i++)
    {
        printf("%d %d\n",-(i+1),-(i+1)*(i+1)-10000000);
    }
    return 0;
}