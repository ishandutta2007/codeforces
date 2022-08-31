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
int n;
int a[2][400005],p[400005];
bool vis[400005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=0;i<2;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
		for(int i=1;i<=n;i++) p[a[0][i]]=a[1][i];
		for(int i=1;i<=n;i++) vis[i]=0;
		ll ans=1;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			vis[i]=1;
			for(int j=p[i];!vis[j];j=p[j]) vis[j]=1;
			ans=ans*2%cys;
		}
		printf("%lld\n",ans);
	}
	return 0;
}