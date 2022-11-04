#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<string>
#include<set>
#include<map>
typedef long long ll;
#define mm(a) memset(a,0,sizeof(a))
#define lr rt<<1
#define rr rt<<1|1
#define sync std::ios::sync_with_stdio(false);std::cin.tie(0);
#define inf 0x3f3f3f3f
#define maxn 500010
using namespace std;
int a[200005];
int main()
{
    sync
    int n;
    cin>>n;
    int aa;
    for(int i=0;i<n;i++)
    {
        cin>>aa;
        a[aa]++;
    }
    int sum=0;
    for(int i=1;i<=200000;i++)
    {
        if(a[i]>0)
        {
            sum++;
            a[i]--;
        }
        else if(a[i-1]>0)
        {
            sum++;
            a[i-1]--;
        }
        else if(a[i+1]>0)
        {
            sum++;
            a[i+1]--;
        }
        if(a[i]>0)
        {
            a[i+1]++;
        }
    }
    cout<<sum<<endl;
    return 0;
}