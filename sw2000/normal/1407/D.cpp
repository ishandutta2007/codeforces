#include <bits/stdc++.h>
#define x first
#define y second
#define mid (l+r>>1)
#define lo (o<<1)
#define ro (o<<1|1)
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;
struct tri{int x,y,z;};
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int N=3e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

int arr[N],ans[N];
int up[N],n1,down[N],n2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    memset(ans,0x3f,sizeof(ans));
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    ans[1]=0;
    up[++n1]=1;
    down[++n2]=1;
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            ans[i]=ans[i-1]+1;
            n1--;n2--;
        }
        else if(arr[i]>arr[i-1])
        {
            while(n2&&arr[down[n2]]<arr[i])
            {
                ans[i]=min(ans[i],ans[down[n2]]+1);
                n2--;
            }
            if(n2)
            {
                ans[i]=min(ans[i],ans[down[n2]]+1);
                if(arr[i]==arr[down[n2]])n2--;
            }
        }
        else
        {
            while(n1&&arr[up[n1]]>arr[i])
            {
                ans[i]=min(ans[i],ans[up[n1]]+1);
                n1--;
            }
            if(n1)
            {
                ans[i]=min(ans[i],ans[up[n1]]+1);
                if(arr[i]==arr[up[n1]])n1--;
            }
        }
        up[++n1]=i;
        down[++n2]=i;
    }
    cout<<ans[n];
    return 0;
}