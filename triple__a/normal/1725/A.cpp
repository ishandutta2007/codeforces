#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    if(m==1) printf("%d\n",n-1);
    else printf("%lld\n",1LL*n*(m-1));
    return 0;
}