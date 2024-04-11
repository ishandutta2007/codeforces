#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 500000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int a[maxn+5];
int cnt[maxn+5];
int mm[maxn+5];

int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    rep(i,1,n) scanf("%d",&a[i]);
    int CC=0;
    rep(i,1,n) CC+=a[i]==c;
    rep(i,1,n) mm[i]=inf;
    int ans=0;
    rep(i,1,n)
    {
        int now=a[i];
        int oldx=cnt[now]-cnt[c];
        cnt[now]++;
        int x=cnt[now]-cnt[c];
        ans=max(ans,x-mm[now]);
        ans=max(ans,x-oldx);
        mm[now]=min(mm[now],oldx);
    }
    printf("%d\n",CC+ans);
    return 0;
}