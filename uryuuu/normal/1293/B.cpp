#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<time.h>
#include<cstdlib>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=300005;
const ll Mod=1e9+7;


int main()
{
    int n;
    cin>>n;
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=1.0*1.0/i;
    }
    printf("%6lf\n",sum);
    return 0;
}