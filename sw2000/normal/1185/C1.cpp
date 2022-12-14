#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 110;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
	int n,m,a[maxn],sum[maxn]={0};
	cin >> n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i];
        if(sum[i]<=m)cout<<"0 ";
        else
        {
            sort(a+1,a+i,cmp);
            int tmp=0;
            for(int j=1;j<i;j++)
            {
                tmp+=a[j];
                if(sum[i]-tmp<=m)
                {
                    cout<<j<<' ';
                    break;
                }
            }
        }
    }

	return 0;
}