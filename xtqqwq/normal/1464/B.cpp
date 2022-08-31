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

int n,x,y;
char s[100005];
int cnt0[100005],cnt1[100005],cntq[100005];
ll pre0[100005],pre1[100005],suf0[100005],suf1[100005];

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	x=readint(); y=readint();
	int n0=0,n1=0; ll ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') n0++;
		else if(s[i]=='1') n1++;
	}
	for(int i=1;i<=n;i++){
		cnt0[i]=cnt0[i-1]+(s[i]=='0');
		cnt1[i]=cnt1[i-1]+(s[i]=='1');
		cntq[i]=cntq[i-1]+(s[i]=='?');
		if(s[i]=='0') ans+=1ll*y*cnt1[i];
		else if(s[i]=='1') ans+=1ll*x*cnt0[i];
		else{
			pre0[i]=1ll*y*cnt1[i]+1ll*x*(n1-cnt1[i]),pre1[i]=1ll*x*cnt0[i]+1ll*y*(n0-cnt0[i]);
			suf0[i]=1ll*y*cnt1[i]+1ll*x*(n1-cnt1[i]),suf1[i]=1ll*x*cnt0[i]+1ll*y*(n0-cnt0[i]);
		}
	}
	for(int i=1;i<=n;i++) pre0[i]+=pre0[i-1],pre1[i]+=pre1[i-1];
	for(int i=n;i>=1;i--) suf0[i]+=suf0[i+1],suf1[i]+=suf1[i+1];
	ll now=1ll<<60;
	for(int i=0;i<=n;i++){
		chkmin(now,pre0[i]+suf1[i+1]+1ll*x*cntq[i]*(cntq[n]-cntq[i]));
		chkmin(now,pre1[i]+suf0[i+1]+1ll*y*cntq[i]*(cntq[n]-cntq[i]));
	}
	printf("%lld\n",ans+now);
	return 0;
}