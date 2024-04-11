#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int maxn=2e5+10;
const ll mod=998244353;
 
int arr[maxn];
ll ans=1;
 
int main()
{
    int n,k,pre=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int a;scanf("%d",&a);
        if(a>=n-k+1)
        {
            if(pre)ans*=i-pre;
            ans%=mod;
            pre=i;
        }
    }
    printf("%lld ",(ll)(2*n-k+1)*k/2);
    printf("%d",ans);
 
	return 0;
}