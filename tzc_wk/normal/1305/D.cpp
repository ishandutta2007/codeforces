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
int n=read();
vector<int> g[1005];
inline void dfs(int x,int fa){
	vector<int> v;
	foreach(it,g[x]){
		if(*it!=fa){
			v.push_back(*it);
		}
	}
	for(int i=0;i+1<v.size();i+=2){
		cout<<"? "<<v[i]<<" "<<v[i+1]<<endl;fflush(stdout);
		int val;cin>>val;
		if(val==v[i]){
			dfs(v[i],x);
			exit(0);
		}
		if(val==v[i+1]){
			dfs(v[i+1],x);
			exit(0);
		}
	}
	if(v.size()%2){
		int y=v.back();
		vector<int> vv;
		foreach(it,g[y]){
			if(*it!=x){
				vv.push_back(*it);
			}
		}
		if(!vv.size()){
			cout<<"? "<<y<<" "<<x<<endl;fflush(stdout);
			int val;cin>>val;cout<<"! "<<val<<endl;fflush(stdout);
			exit(0);
		}
		else{
			int z=vv.back();
			cout<<"? "<<x<<" "<<z<<endl;fflush(stdout);
			int val;cin>>val;
			if(val==z){
				dfs(z,y);
				exit(0);
			}
			else if(val==x){
				cout<<"! "<<x<<endl;fflush(stdout);exit(0);
			}
			else{
				vv.pop_back();
				g[y]=vv;
				dfs(y,x);exit(0);
			}
		}
		exit(0);
	}
	cout<<"! "<<x<<endl;fflush(stdout);
	exit(0);
}
signed main(){
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
//	if(n==2){
//		cout<<"? 1 2"<<endl;fflush(stdout);
//		int x;cin>>x;cout<<"! "<<x<<endl;fflush(stdout);
//		return 0;
//	}
//	fz(i,1,n){
//		if(g[i].size()>1){
//			dfs(i,0);
//			return 0;
//		}
//	}
	return 0;
}