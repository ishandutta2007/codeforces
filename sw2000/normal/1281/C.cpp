#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=3e6+10;
const ll mod=1e9+7;
int arr[maxn];

int main()
{
//    freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,len;
        char s[510];
        scanf("%d%s",&x,s);
        len=strlen(s);
        for(int i=1;i<=len;i++)
        {
            arr[i]=s[i-1]-'0';
        }

        ll ans=len,left=len-1;
        for(int i=1,id=len+1;i<=x;i++)
        {
            ans+=left*(arr[i]-1);
            ans%=mod;
            left=(ans-i+mod-1)%mod;

            if(id<=x)
            {
                int cnt=arr[i]-1,l=i+1,r=id-1;
                while(cnt--)
                {
                    for(int j=l;j<=r;j++)
                    {
                        arr[id++]=arr[j];
                    }
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}