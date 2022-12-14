#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2000+10;
const int inf=0x3f3f3f3f;
const ll mod=2147493647;

int arr[maxn],n,k;
struct Ans
{
    int l,r;
};

void rev(int l,int r)
{
    int mid=r-l>>1;

    for(int i=0;i<=mid;i++)
    {
        swap(arr[l+i],arr[r-i]);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        vector<Ans>ans;
        vector<int>v;
        scanf("%d%d",&n,&k);
        string str;
        cin>>str;
        for(int i=0;i<n;i++)
        {
            if(str[i]=='(')arr[i+1]=1;
            else arr[i+1]=-1;
        }

        int sum=0;
        for(int l=1,r=1,cnt=0;r<=n;r++)
        {
            if(cnt+arr[r]==0)
            {
                if(cnt<0)
                {
                    ans.push_back({l,r});
                    rev(l,r);
                }
                sum++;
                l=r+1;
                v.push_back(r);
                cnt=0;
            }
            else cnt+=arr[r];
        }

        if(sum>k)
        {
            for(int i=0;i<sum-k;i++)
            {
                ans.push_back({v[i],v[i]+1});
            }
        }
        if(sum<k)
        {
            for(int i=1;i<=k-sum;i++)
            {
                for(int j=2;j<=n;j++)
                {
                    if(arr[j]==1&&arr[j-1]==1)
                    {
                        int l=j,r=j;
                        while(arr[r]==1)r++;
                        ans.push_back({l,r});
                        rev(l,r);
                        break;
                    }
                }
            }
        }

        printf("%d\n",ans.size());
        for(auto i:ans)
            printf("%d %d\n",i.l,i.r);
    }
    return 0;
}