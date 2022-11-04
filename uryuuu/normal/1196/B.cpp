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
const ll Mod=998244353;
using namespace std;
int dd[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int a[200005],b[200005];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int kk=0;
        int j=0;
        while(j<n)
        {
            if(a[j]%2)
                b[kk++]=j;
            j++;
        }
        if(kk>=k&&((kk-k)%2==0))
        {
            cout<<"YES"<<endl;
            for(int i=0;i<k-1;i++)
            {
                cout<<b[i]+1<<' ';
            }
            cout<<n<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}