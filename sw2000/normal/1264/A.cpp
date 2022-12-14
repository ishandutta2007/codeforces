#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=4e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int arr[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        vector<int>v;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]!=arr[i-1])
            {
                v.push_back(cnt);
                cnt=0;
            }
            cnt++;
        }
        v.push_back(cnt);
//        for(auto i:v)cout<<i<<' ';
//        cout<<endl;
        if(v.size()<=3)
        {
            puts("0 0 0");
            continue;
        }
        int sum=0;
        for(int i=1;i<v.size();i++)
        {
            sum+=v[i];
            if(sum+v[0]>n/2)
            {
                sum-=v[i];
                break;
            }
        }
        cnt=0;
        for(int i=1;i<v.size();i++)
        {
            cnt+=v[i];
            if(cnt>v[0]&&sum-cnt>v[0])
            {
                printf("%d %d %d\n",v[0],cnt,sum-cnt);
                break;
            }
            if(i==v.size()-1)
            {
                puts("0 0 0");
            }
        }
    }
    return 0;
}