#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

int main()
{
	int n,m,a,cnt[110]={0};
	scanf("%d%d",&n,&m);;
	for(int i=1;i<=n;i++)
    {
        scanf("%d",&a);
        int sum=0,sub=0;
        for(int j=1;j<101;j++)
        {
            if(sum+j*cnt[j]<=m-a)
            {
                sum+=j*cnt[j];
                sub+=cnt[j];
            }
            else
            {
                sub+=(m-sum-a)/j;
                break;
            }
        }

        printf("%d ",i-1-sub);
        cnt[a]++;
    }

	return 0;
}