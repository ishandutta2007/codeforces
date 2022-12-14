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
const int N=5e5+10;
const ll mod=1e9+7;
const double PI=acos(0)*2;

string s;
char a,b;
int n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
//    freopen("in.txt","r",stdin);
    cin>>n>>k;
    cin>>s;
    cin>>a>>b;
    if(a==b)
    {
        int cnt=0;
        for(auto i:s)if(i==a)cnt++;
        cnt=min(cnt+k,n);
        cout<<cnt*(cnt-1)/2;
        return 0;
    }

    int ca=0,cb=0;
    for(auto i:s)
    {
        if(i==a)cb++;
        if(i==b)ca++;
    }

    int ans=0;
    for(int i=0;i<=ca;i++)
    {
        for(int j=0;j<=cb;j++)
        {
            if(i+j>k)break;
            int t[210]={};
            int ii=i,jj=j;
            for(int i=0;i<n;i++)if(s[i]==b)
            {
                if(ii)
                {
                    t[i]=1;
                    ii--;
                }
                else t[i]=-1;
            }
            for(int i=n-1;~i;i--)if(s[i]==a)
            {
                if(jj)
                {
                    t[i]=-1;
                    jj--;
                }
                else t[i]=1;
            }
            int cnt=0,now=0;
            for(int i=0;i<n;i++)
            {
                if(t[i]==1)cnt++;
                else if(t[i]==-1)now+=cnt;
            }
            int pre[210]={},suf[210]={};
            for(int i=0;i<n;i++)
            {
                if(t[i]==1)pre[i]++;
                if(i)pre[i]+=pre[i-1];
            }
            for(int i=n-1;~i;i--)
            {
                if(t[i]==-1)suf[i]++;
                suf[i]+=suf[i+1];
            }
            vi can;
            for(int i=0;i<n;i++)if(!t[i])
            {
                can.push_back(i);
            }
            int l=min((int)can.size()-1,k-i-j-1),r=can.size();
            for(int i=0;i<=l;i++)now+=suf[can[i]];
            ans=max(ans,now);
            while(l!=-1)
            {
                now-=suf[can[l--]];
                now+=pre[can[--r]];
                ans=max(ans,now+(int)(can.size()-r)*(l+1));
            }

        }
    }
    cout<<ans;
    return 0;
}