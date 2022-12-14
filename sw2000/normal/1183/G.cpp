#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
int disa[maxn],disb[maxn];

struct Sum
{
    int a;
    vector<int>b;
}sum[maxn];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,cnt=0,ans1=0,ans2=0;
        priority_queue<int>pq;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            disa[a]++;
            disb[a]+=b;
        }
        for(int i=1;i<=n;i++)
        {
            if(disa[i]!=0)
            {
                sum[disa[i]].a++;
                sum[disa[i]].b.push_back(disb[i]);
            }
        }
        for(int i=n;i;i--)
        {
            cnt+=sum[i].a;
            for(int j=0;j<sum[i].a;j++)
            {
                pq.push(sum[i].b[j]);
            }
            if(cnt)
            {
                ans1+=i;
                int tmp=pq.top();
                if(tmp>i)ans2+=i;
                else ans2+=tmp;
                pq.pop();
                cnt--;
            }
        }
        printf("%d %d\n",ans1,ans2);
        for(int i=0;i<=n;i++)
        {
            disa[i]=0;
            disb[i]=0;
            sum[i].a=0;
            sum[i].b.clear();
        }
    }
    return 0;
}