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

const int cys=998244353;
int n,m;
ll d[3005][3005];
char s[3005],t[3005];

ll mod(ll x){return x>=cys?x-cys:x;}

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++) if(i>m||s[1]==t[i]) d[i][i]=2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int l=j,r=j+i-1,pl=i+1;
			if(l>1&&(l-1>m||s[pl]==t[l-1])) d[l-1][r]=mod(d[l-1][r]+d[l][r]);
			if(r<n&&(r+1>m||s[pl]==t[r+1])) d[l][r+1]=mod(d[l][r+1]+d[l][r]);
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++) ans=mod(ans+d[1][i]);
	printf("%lld\n",ans);
	return 0;
}