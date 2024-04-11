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
int T=read();
int n,a[1005],ans[1005];
bool used[1005];
vector<int> fac[1005];
inline void solve(){
	n=read();
	fill0(used);fill0(ans);
	fz(i,1,n)	a[i]=read();
	fz(i,1,n)	fac[i].clear();
	fz(i,1,n){
		int tmp=a[i];
		for(int j=2;j*j<=a[i];j++){
			if(tmp%j==0){
				while(tmp%j==0)	tmp/=j;
				fac[i].push_back(j);
				used[j]=1;
			}
		}
//		puts("");
		if(tmp>1)	used[tmp]=1;
	}
	vector<int> v;
	fz(i,1,32)	if(used[i])	v.push_back(i);
	int cnt=1;
	for(int i=0;i<v.size();i++){
		bool flag=0;
		fz(j,1,n){	
			if(a[j]%v[i]==0&&!ans[j]){
				ans[j]=cnt;
				flag=1;
			}	
		}
		if(flag){
			cnt++;
		}
	}
	cout<<*max_element(ans+1,ans+n+1)<<endl;
	fz(i,1,n)	cout<<ans[i]<<" ";puts("");
}
signed main(){
	while(T--)	solve();
	return 0;
}