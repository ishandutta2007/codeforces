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

int n;
int c[1005];
ll sum[1005],mina[1005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) c[i]=readint();
	ll ans=0;
	for(int i=1;i<=n;i+=2){
		sum[i-1]=0,mina[i-1]=1<<30;
		for(int j=i;j<=n;j++){
			if(j&1) sum[j]=sum[j-1]+c[j];
			else sum[j]=sum[j-1]-c[j];
			mina[j]=min(mina[j-1],sum[j]);
			if(j&1) continue;
			if(mina[j-1]==c[i]) ans+=max(0ll,mina[j-1]-max(0ll,sum[j]));
			else ans+=max(0ll,mina[j-1]-max(0ll,sum[j])+1);
		}
	}
	printf("%lld\n",ans);
	return 0;
}