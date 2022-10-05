//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),k=read(),a[55];
int dp[55][2][2];
inline int dfs(int l,int r,bool lim1,bool lim2){
	if(~dp[l][lim1][lim2])	return dp[l][lim1][lim2];
	if(l+1>r-1)				return 1;
	int ans=0;
	dp[l][lim1][lim2]=0;
	for(int k1=0;k1<2;k1++){
		if((a[l+1]==k1||a[l+1]==-1))
		for(int k2=0;k2<2;k2++){
			if(l+1==r-1&&k1!=k2)	continue;
			if((a[r-1]==k2||a[r-1]==-1)){
				if((!lim1||(k1<=k2))&&(!lim2||(k1<=1-k2))){
					ans+=dfs(l+1,r-1,lim1&(k1==k2),lim2&(k1!=k2));
				}
			}
		}
	}
	dp[l][lim1][lim2]=ans;
//	cout<<l<<" "<<r<<" "<<lim1<<" "<<lim2<<" "<<ans<<endl;
	return ans;
}
signed main(){
	fill1(a);
	fill1(dp);k++;
//	cout<<dfs(0,n+1,1,1)<<endl;
	if(dfs(0,n+1,1,1)<k){
		return puts("-1"),0;
	}
	fz(i,1,n){
		fill1(dp);
		a[i]=0;
		int sum=dfs(0,n+1,1,1);
//		cout<<sum<<" "<<k<<endl;
		if(sum<k){
			k-=sum;a[i]=1;
		}
	}
//	if(k>0){
//		puts("-1");
//		return 0;
//	}
	a[0]=0;
	fz(i,1,n)	putchar(a[i]^48);
	return 0;
}