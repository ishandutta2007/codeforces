#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;

int main()
{
	int n,a[maxn];
	cin>>n;
	int st=1,en=n,now=0,ans=0;
	char ans2[maxn]={0};
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);

	while(1)
    {
        if(st>en||max(a[st],a[en])<=now)
        {
            break;
        }
        if(a[en]==a[st])
        {
            int l=1,r=1;
            for(int i=st+1;i<=en;i++)
            {
                if(a[i]>a[i-1])l++;
                else break;
            }
            for(int i=en-1;i>=st;i--)
            {
                if(a[i]>a[i+1])r++;
                else break;
            }
            if(l>r)
            {
                for(int i=0;i<l;i++)
                {
                    ans2[ans]='L';
                    ans++;
                }
            }
            else
            {
                for(int i=0;i<r;i++)
                {
                    ans2[ans]='R';
                    ans++;
                }
            }
            break;
        }
        if(a[st]>now&&a[en]<=now)
        {
            ans2[ans]='L';
            ans++;
            now=a[st];
            st++;
        }
        else if(a[en]>now&&a[st]<=now)
        {
            ans2[ans]='R';
            ans++;
            now=a[en];
            en--;
        }
        else
        {
            if(a[st]<a[en])
            {
                ans2[ans]='L';
                ans++;
                now=a[st];
                st++;
            }
            else
            {
                ans2[ans]='R';
                ans++;
                now=a[en];
                en--;
            }
        }
    }
    printf("%d\n%s",ans,ans2);
    return 0;
}