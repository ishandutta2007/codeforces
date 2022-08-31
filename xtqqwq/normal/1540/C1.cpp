#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m,q,x;
int c[105],b[105],s1[105],s2[105],d[105][10005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	n=readint();
	int sum=0;
	for(int i=1;i<=n;i++) c[i]=readint(),sum+=c[i];
	for(int i=1;i<n;i++) b[i]=readint();
	q=readint(); x=readint();
	s1[1]=s2[1]=x;
	for(int i=2;i<=n;i++){
		s1[i]=s1[i-1]+b[i-1];
		s2[i]=s2[i-1]+s1[i];
	}
	d[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=c[i];j++)
			for(int k=max(0,s2[i]-j);k<=sum-j;k++)
				d[i][k+j]=mod(d[i][k+j]+d[i-1][k]);
	ll ans=0;
	for(int i=0;i<=sum;i++) ans=mod(ans+d[n][i]);
	printf("%lld\n",ans);
	return 0;
}