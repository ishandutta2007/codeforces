#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int inf=0x3f3f3f3f;

struct A
{
    int a,id;
}arr[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].a;
            arr[i].id=i+1;
            ans+=arr[i].a;
        }

        if(m<n||n==2)
        {
            puts("-1");
            continue;
        }

        sort(arr,arr+n,[](A a,A b){return a.a<b.a;});
        ans*=2;
        ans+=(m-n)*(arr[0].a+arr[1].a);
        printf("%d\n",ans);
        for(int i=0;i<m-n;i++)
        {
            printf("%d %d\n",arr[0].id,arr[1].id);
        }
        printf("%d %d\n",arr[0].id,arr[n-1].id);
        for(int i=0;i<n-1;i++)
        {
            printf("%d %d\n",arr[i].id,arr[i+1].id);
        }

    }
    return 0;
}