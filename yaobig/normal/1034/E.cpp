#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn (1<<21)
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

char sa[maxn+5],sb[maxn+5];
ull a[maxn+5],b[maxn+5];
int cnt[maxn+5];

int N;
void fwt(ull *a,int opt)
{
    for(int i=1;i<N;i<<=1)
        for(int p=i<<1,j=0;j<N;j+=p)
            rep(k,0,i-1)
                if(opt==1) a[i+j+k]=a[j+k]+a[i+j+k];
                else a[i+j+k]=a[i+j+k]-a[j+k];
}

int main()
{
    int n; scanf("%d%s%s",&n,sa,sb);
    N=1<<n;
    rep(i,1,N-1) cnt[i]=cnt[i>>1]+(i&1);
    rep(i,0,N-1) a[i]=(ull)(sa[i]-'0')<<(cnt[i]*2);
    rep(i,0,N-1) b[i]=(ull)(sb[i]-'0')<<(cnt[i]*2);
    fwt(a,1);
    fwt(b,1);
    rep(i,0,N-1) a[i]*=b[i];
    fwt(a,-1);
    rep(i,0,N-1) printf("%c",((a[i]>>(cnt[i]*2))&3)+'0');
    puts("");
    return 0;
}