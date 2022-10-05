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
int n=read(),m=read(),q=read();
int a[105],b[105],c[105],u[15],v[15];
vector<int> g[15];
int dp[14][8193];
signed main(){
	fz(i,1,m)	u[i]=read(),v[i]=read(),g[u[i]].push_back(v[i]),g[v[i]].push_back(u[i]);
	fz(i,1,q)	a[i]=read(),b[i]=read(),c[i]=read();
	for(int j=0;j<(1<<n);j++){
		for(int i=1;i<=n;i++){
			if(__builtin_popcount(j)==1&&_bit(j,i-1)){
				dp[i][j]=1;
				continue;
			}
			if(!_bit(j,i-1))	continue;
			int msk=j-mask(i-1);
			int fst=0;
			for(int t=1;t<=n;t++)
				if(_bit(msk,t-1)){
					fst=t;
					break;
				}
//			cout<<msk<<endl;
//			cout<<"fst="<<fst<<endl;
			for(int k=msk;k;k=msk&(k-1)){
				if(_bit(k,fst-1)){
					int l=k^j;
					int cnt=0,s=0;
					foreach(it,g[i]){
						int p=*it;
						if(_bit(k,p-1))	s=p,cnt++;
					}
					if(cnt>=2)	continue;
					bool flag=1;
					for(int p=1;p<=m;p++){
						if(u[p]==i||v[p]==i)	continue;
						if(_bit(k,u[p]-1)&&!_bit(k,v[p]-1))	flag=0;
						if(_bit(k,v[p]-1)&&!_bit(k,u[p]-1))	flag=0;
					}
					for(int r=1;r<=q;r++){
						if(_bit(k,c[r]-1)&&(!_bit(k,a[r]-1)||!_bit(k,b[r]-1)))	flag=0;
						if(c[r]==i&&_bit(k,a[r]-1)&&_bit(k,b[r]-1))				flag=0;
					}
					if(!flag)	continue;
//					int tmp=dp[i][j];
					if(!cnt){
						for(int o=1;o<=n;o++){
							if(i!=o&&_bit(k,o-1))	dp[i][j]+=dp[i][l]*dp[o][k];
						}
					}
					else{
						dp[i][j]+=dp[i][l]*dp[s][k];
					}
//					cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j]-tmp<<endl;
				}
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[1][(1<<n)-1]<<endl;
	return 0;
}