#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;

int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
    {
        int n,ans=inf;
        map<int,int>m;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            if(m[a])
            {
                ans=min(ans,i-m[a]+1);
            }
            m[a]=i;
        }
        if(ans==inf)
        {
            puts("-1");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
	return 0;
}