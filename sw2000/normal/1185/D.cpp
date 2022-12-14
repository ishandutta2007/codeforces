#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+10;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;

struct A
{
    int v;
    int j;
    int gap;
}a[maxn];

bool cmp(A tmp1,A tmp2)
{
    return tmp1.v<tmp2.v;
}

int main()
{
	int n,ma=-1;
	cin>>n;
	for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].v);
        a[i].j=i+1;
    }

    sort(a,a+n,cmp);
    for(int i=1;i<n;i++)
    {
        a[i].gap=a[i].v-a[i-1].v;
        ma=max(a[i].gap,ma);
    }
    bool flag=1;
    for(int i=3;i<n;i++)
    {
        if(a[i].gap!=a[i-1].gap)
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<a[0].j;
        return 0;
    }
    flag=1;
    for(int i=2;i<n-1;i++)
    {
        if(a[i].gap!=a[i-1].gap)
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        cout<<a[n-1].j;
        return 0;
    }

    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i].gap!=ma)cnt++;
    }
    if(cnt==1)
    {
        for(int i=1;i<n;i++)
        {
            if(a[i].gap!=ma&&a[i].gap==0)
            {
                cout<<a[i].j;
                return 0;
            }
        }
        cout<<-1;
        return 0;
    }
    if(cnt==2)
    {
        for(int i=1;i<n-1;i++)
        {
            if(a[i].gap!=ma&&a[i+1].gap!=ma&&a[i].gap+a[i+1].gap==ma)
            {
                cout<<a[i].j;
                return 0;
            }
        }
    }
    cout<<-1;
	return 0;
}