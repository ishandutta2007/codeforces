#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define rep(i,a,n) for (int i = a; i <= (int)n; ++i)
#define dep(i,a,n) for (int i = a; i >= (int)n; --i)
#define re(b,a) for(a::iterator it=b.begin();it!=b.end();++it)
#define clr(a,b) memset(a,sizeof(a),b);
#define inf 0x7fffffff
#define eps 1e-8
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
inline void read(int &n)
{
    char c;
    for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar());
    n = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int l,m,n,t,a[11111111],r,Min,Max,prime[1111111],p[11111111],tot;
ll c[1111111];
vector<int>pri,vec;
/*void fen(int x)
{
    for(int i=2;i*i<=x;++i){if(x%i==0)pri.pb(i);while(x%i==0)x/=i;}
    if(x!=1)pri.pb(x);
}
void ff(int x)
{
    for(int i=2;i*i<=x;++i){if(x%i==0)c[b[i]]++;while(x%i==0)x/=i;}
    if(x!=1)c[b[x]]++;
}
void modi(int k,int x){for(int i=k;i<=n;i+=i&-i)a[i]+=x;}
int que(int x){int ans=0;for(int i=x;i;i-=i&-i)ans+=a[i];return ans;}*/
int main()
{
    scanf("%d",&n);rep(i,1,n)scanf("%d",&t),m=max(m,t),a[t]++;n=m;
    rep(i,2,n){if(!p[i])prime[++tot]=i;rep(j,1,tot)if(prime[j]*i<=n)p[prime[j]*i]=1;else break;}
    memset(p,0,sizeof(p));rep(i,1,tot)p[prime[i]]=i;
    rep(i,1,tot)for(int j=1;j*prime[i]<=n;++j)c[i]+=a[j*prime[i]];
    //sort(pri.begin(),pri.end());
    //if(pri.size())vec.pb(pri[0]);
    //rep(i,0,vec.size()-1)printf("%d %d %d\n",i,vec[i],c[i]);puts("");
    //rep(i,1,pri.size()-1)if(pri[i]!=pri[i-1])vec.pb(pri[i]);
    //rep(i,0,vec.size()-1)printf("%d %d %d\n",i,vec[i],c[i]);puts("");
    //rep(i,0,vec.size()-1)b[vec[i]]=i;
    //rep(i,1,n)ff(a[i]);
    memset(a,0,sizeof(a));
    rep(i,2,tot)c[i]+=c[i-1];
    //rep(i,1,tot)printf("%d %d\n",prime[i],c[i]);
    //rep(i,0,vec.size()-1)printf("%d %d %d %d\n",i,vec[i],c[i],que(i));puts("");
    scanf("%d",&m);while(m--)
    {
        scanf("%d%d",&l,&r);if(l>n){puts("0");continue;}
        if(r>n)r=n;
        //printf("%d %d\n",l,r);
        Min=1;Max=tot;while(Min<Max){int mid=Min+Max>>1;if(prime[mid]<l)Min=mid+1;else Max=mid;}l=Min;
        Min=1;Max=tot;while(Min<Max){int mid=Min+Max+1>>1;if(prime[mid]>r)Max=mid-1;else Min=mid;}r=Min;
        //printf("%d %d\n",l,r);
        printf("%I64d\n",max(0ll,c[r]-c[l-1]));
    }
    return 0;
}