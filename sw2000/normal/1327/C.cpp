#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    printf("%d\n",n+m+n*m-3);
    for(int i=0;i<m-1;i++)printf("L");
    for(int i=0;i<n-1;i++)printf("U");
    for(int i=0;i<n;i++)
    {
        if(i)printf("D");
        for(int j=0;j<m-1;j++)
        {
            if(i%2==0)printf("R");
            else printf("L");
        }
    }
	return 0;
}