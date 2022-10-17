#include<vector>
#include<algorithm>
#include<utility>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<time.h>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
#include<set>
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define rf(i,n) for(int i=n-1;i>=0;i--)
#define of(i,n) for(int i=n;i>0;i--)
#define scan(x) scanf("%d",&x);
#define scans(x) scanf("%s",&x);
#define scand(x) scanf("%lf",x);
#define print(x) printf("%d ",x);
const int inf=0x3fffffff;
const double pi=acos(-1.);
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef set<int> si;
typedef vector<int> vi;
int n;
long long m;
int a[100020];
int main()
{
    int i,j,k;
    scanf("%d %I64d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    for(i=0;i<n;)
    {
        for(j=i;a[j]==a[i];j++);
        k=j-i;
        if(m>(ll)k*n)
            m-=(ll)k*n;
        else
        {
            printf("%d %d\n",a[i],a[(m-1)/k]);
            break;
        }
        i=j;
    }
    return 0;
}