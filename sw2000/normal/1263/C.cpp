#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const ll linf=0x3f3f3f3f3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v;
        v.push_back(0);
        for(int i=1;i*i<=n;i++)
        {
            v.push_back(i);
            if(i!=n/i)v.push_back(n/i);
        }
        sort(v.begin(),v.end());
        printf("%d\n",v.size());
        for(auto i:v)
            printf("%d ",i);
        printf("\n");
    }
    return 0;
}