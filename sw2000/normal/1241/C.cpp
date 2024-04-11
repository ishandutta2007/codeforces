#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;

int arr[maxn];
int x,y,a,b;
ll k;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",&arr[i]);
        sort(arr,arr+n,cmp);
        cin>>x>>a>>y>>b>>k;
        if(x<y)
        {
            swap(x,y);
            swap(a,b);
        }
        int gap[3];
        memset(gap,-1,sizeof(gap));
        for(int i=1;i<=n;i++)
        {
            if(i%a==0&&i%b==0)
            {
                k-=arr[++gap[0]]/100*y;
                k-=arr[++gap[1]]/100*(x-y);
                k-=arr[++gap[2]]/100*y;
            }
            else if(i%a==0)
            {
                k-=arr[++gap[1]]/100*(x-y);
                k-=arr[++gap[2]]/100*y;
            }
            else if(i%b==0)
            {
                k-=arr[++gap[2]]/100*y;
            }

            if(k<=0)
            {
                cout<<i<<endl;
                break;
            }
        }
        if(k>0)
        {
            cout<<-1<<endl;
        }
    }
	return 0;
}