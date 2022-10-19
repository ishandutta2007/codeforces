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
int d=read(),tmp=d;
vector<pii> fac;
map<int,vector<pii> > facs;
inline void dfs(int x,int mul,vector<pii> f){
	if(x==fac.size()){
		facs[mul]=f;
		return;
	}
	for(int i=0;i<=fac[x].se;i++){
		f.push_back({x,i});
		dfs(x+1,mul*pow(fac[x].fi,i),f);
		f.pop_back();
	}
}
const int MOD=998244353;
int C[5005][5005],cnt1[15],cnt2[15],cnt_dif[15];
signed main(){
	fz(i,0,5000){
		C[i][0]=1;
	}
	fz(i,1,5000){
		fz(j,1,i){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
//			cout<<i<<" "<<j<<" "<<C[i][j]<<endl;
		}
	}
	for(int i=2;i*i<=d;i++){
		if(tmp%i==0){
			int cnt=0;
			while(tmp%i==0){
				tmp/=i;
				cnt++;
			}
			fac.push_back({i,cnt});
		}
	}
//	for(int i=0;i<fac.size();i++){
//		cout<<fac[i].fi<<" "<<fac[i].se<<endl;
//	}
	if(tmp>1){
		fac.push_back({tmp,1});
	}
	vector<pii> wasted;
	dfs(0,1,wasted);
	int Q=read();
	while(Q--){
		int x=read(),y=read();
		vector<pii> _x=facs[x];
		vector<pii> _y=facs[y];
		fill0(cnt1);fill0(cnt2);fill0(cnt_dif);
		for(int i=0;i<_x.size();i++){
//			cout<<_x[i].fi<<" "<<_x[i].se<<endl;
			cnt1[_x[i].fi]=_x[i].se;
		}
		for(int i=0;i<_y.size();i++){
//			cout<<_y[i].fi<<" "<<_y[i].se<<endl;
			cnt2[_y[i].fi]=_y[i].se;
		}
		for(int i=0;i<_x.size();i++){
			cnt_dif[_x[i].fi]=cnt1[_x[i].fi]-cnt2[_x[i].fi];
		}
		for(int i=0;i<_y.size();i++){
			cnt_dif[_y[i].fi]=cnt1[_y[i].fi]-cnt2[_y[i].fi];
		}
		int sum1=0,sum2=0;
		for(int i=0;i<fac.size();i++){
			if(cnt_dif[i]>0)	sum1+=cnt_dif[i];
			if(cnt_dif[i]<0)	sum2-=cnt_dif[i];
		}
		int ans=1;
		for(int i=0;i<fac.size();i++){
//			cout<<cnt_dif[fac[i].fi]<<endl;
			if(cnt_dif[i]>0){
				ans=ans*C[sum1][cnt_dif[i]]%MOD;
				sum1-=cnt_dif[i];
			}
			if(cnt_dif[i]<0){
				ans=ans*C[sum2][-cnt_dif[i]]%MOD;
				sum2+=cnt_dif[i];
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}