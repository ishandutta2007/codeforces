#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int arr[maxn],brr[maxn],n;
vector<int>v;

int main()
{
    cin>>n;
//    for(int i=1;i<=n;i++)
//    {
//        scanf("%d",&arr[i]);
//    }
    map<int,int>m;
    int sum=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        scanf("%d",&a);
        if(a>0)
        {
            if(m[a])
            {
                puts("-1");
                return 0;
            }
            else
            {
                m[a]=1;
                cnt++;
            }
        }
        else
        {
            if(m[-a]==1)
            {
                cnt--;
                m[-a]=-1;
                if(cnt==0)
                {
                    m.clear();
                    v.push_back(i-sum);
                    sum=i;
                }
            }
            else
            {
                puts("-1");
                return 0;
            }
        }
    }
    if(cnt!=0)
    {
        puts("-1");
        return 0;
    }
    printf("%d\n",v.size());
    for(auto i:v)
        printf("%d ",i);
    return 0;
}