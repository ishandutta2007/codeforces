#include<bits/stdc++.h>
#define rep(i,a,n) for(i=a;i<=n;i++)
#define maxn 10
#define pb push_back
#define F first
#define S second
using namespace std;
int a[maxn+5][3]={0,1,2,1,0,2,1,2,0,2,1,0,2,0,1,0,2,1},n;
int main()
{
    int i,x;
    scanf("%d%d",&n,&x);
    printf("%d\n",a[n%6][x]);
    return 0;
}