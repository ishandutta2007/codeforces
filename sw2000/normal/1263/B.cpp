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
        int n,ans=0;
        cin>>n;
        map<string,int>m;
        string a[20];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m[a[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(m[a[i]]>1)
            {
                m[a[i]]--;
                ans++;
                for(int j=0;j<10;j++)
                {
                    a[i][0]='0'+j;
                    if(m[a[i]]==0)break;
                }
                m[a[i]]++;
            }
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
    }
    return 0;
}