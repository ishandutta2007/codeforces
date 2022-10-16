#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define maxn 250
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

char s[maxn+5][maxn+5];
vi cnt[maxn+5];
int odd[maxn+5];

vi Ma[maxn*2+5];
vi FUCK1,FUCK2,FUCK3;
int Mp[maxn*2+5];
int ans;
int manacher(int L,int R)
{
    if(L>R) return 0;
    int l=0;
    Ma[l++]=FUCK1;
    Ma[l++]=FUCK2;
    rep(i,L,R)
    {
        Ma[l++]=cnt[i];
        Ma[l++]=FUCK2;
    }
    Ma[l]=FUCK3;
    int mx=0,id=0;
    rep(i,0,l-1)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]]) Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
    rep(i,0,2*(R-L+1)+1) ans+=Mp[i]/2;
    return ans;
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%s",s[i]+1);
    FUCK1.resize(1,-1);
    FUCK2.resize(2,-2);
    FUCK2.resize(3,-3);
    rep(i,1,m)
    {
        rep(t,1,n) cnt[t].clear();
        rep(t,1,n) cnt[t].resize(27,0);
        rep(t,1,n) odd[t]=0;
        rep(j,i,m)
        {
            rep(r,1,n)
            {
                cnt[r][s[r][j]-'a']++;
                if(cnt[r][s[r][j]-'a']&1) odd[r]++;
                else odd[r]--;
                if(odd[r]>=2) cnt[r][26]=r;
                else cnt[r][26]=0;
            }
            //rep(a,1,n) rep(b,0,26) printf("%d%c",cnt[a][b],b==26?'\n':' ');
            odd[n+1]=2;
            int last=0;
            rep(r,1,n+1) if(odd[r]>=2)
            {
                manacher(last+1,r-1);
                last=r;
            }
            //printf("?? %d\n",ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}