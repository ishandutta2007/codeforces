#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 2000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

map<pii,int> cnt;
pii ch[maxn+5];
queue<pii> q;
const int dir[8][2]={-1,2,1,2,-2,1,2,1,-2,-1,2,-1,-1,-2,1,-2};
pii mov[8];
pii operator + (const pii &a,const pii &b)
{
    return mp(a.first+b.first,a.second+b.second);
}


void check(int n)
{
    rep(i,0,7) mov[i]=mp(dir[i][0],dir[i][1]);

    int ans=0;
    rep(i,1,n) q.push(ch[i]),cnt[ch[i]]=-inf;
    ans+=n;
    while(!q.empty())
    {
        pii now=q.front();
        q.pop();
        rep(i,0,7)
        {
            pii nn=now+mov[i];
            cnt[nn]++;
            if(cnt[nn]>=4)
            {
                q.push(nn);
                ans++;
                cnt[nn]=-inf;
            }
        }
    }
    if(ans<(n*n/10)) printf("FUCK");
}
int main()
{
    int n; scanf("%d",&n);
    int N=n;
    int k=(n+2)/3;
    int l=k,u=k-1,d=k-1;
    n-=k*3-2;
    if(n) u++,n--;
    if(n) d++,n--;
    int tot=0;
    rep(i,1,l) ch[++tot]=mp((i-1)*2,0);
    rep(i,1,u) ch[++tot]=mp((i-1)*2+1,1);
    rep(i,1,d) ch[++tot]=mp((i-1)*2+1,-1);
    rep(i,1,tot) printf("%d %d\n",ch[i].first,ch[i].second);
    assert(N==tot);
    //check(tot);
    return 0;
}