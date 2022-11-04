#include<iostream>
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
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define tm(a,b,c) max(max(a,b),c)
#define inf 0x3f3f3f3f
const ll Mod=1e9+7;
#define maxn 50010
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[100005];
int s[100005];
int main()
{
    int n,q;
    cin>>n;
    s[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    cin>>q;
    int a,b;
    for(int i=0;i<q;i++)
    {
        scanf("%d%d",&a,&b);
        cout<<(s[b]-s[a-1])/10<<endl;
    }
    return 0;
}