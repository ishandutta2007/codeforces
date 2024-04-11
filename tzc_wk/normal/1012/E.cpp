/*
Contest: -
Problem: P6305
Author: tzc_wk
Time: 2020.6.13
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
#define y1			y1010101010101
#define y0			y0101010101010
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),s=read(),a[200005],b[200005],c[200005],d[200005],num=0;
vector<int> g[200005],cyc[200005];
int k=0;
inline void dfs(int x){
	while(!g[x].empty()){
		int y=g[x].back();
		g[x].pop_back();
		dfs(a[y]);
		cyc[k].push_back(y);
//		cout<<y<<" ";
	}
}
signed main(){
	fz(i,1,n)	a[i]=read(),c[i]=a[i];
	sort(c+1,c+n+1);
	fz(i,1,n)	if(c[i]!=c[i-1])	d[++num]=c[i];
	fz(i,1,n)	a[i]=lower_bound(d+1,d+num+1,a[i])-d,b[i]=a[i];
	sort(b+1,b+n+1);
	int cnt=0;
//	fz(i,1,n)	cout<<a[i]<<" ";puts("");
//	fz(i,1,n)	cout<<b[i]<<" ";puts("");
	fz(i,1,n){
		if(a[i]!=b[i]){
			cnt++;
			g[b[i]].push_back(i);
		}
	}
	if(!cnt)	return puts("0"),0;
	if(cnt>s)	return puts("-1"),0;
	fz(i,1,num){
		if(!g[i].empty()){
			k++;
			dfs(i);
		}
	}
	fz(i,1,k)	reverse(all(cyc[i]));
	if(k==1){
		cout<<1<<endl<<cyc[1].size()<<endl;
		foreach(it,cyc[1])	cout<<*it<<" ";
		return 0;
	}
	if(cnt<=s-k){
		cout<<2<<endl;
		cout<<cnt<<endl;
		fz(i,1,k){
			foreach(it,cyc[i])	cout<<*it<<" ";
		}
		puts("");
		cout<<k<<endl;
		fd(i,k,1)	cout<<cyc[i][0]<<" ";
		puts("");
		return 0;
	}
	else{
		int t=cnt-(s-k);
		if(t==k)		cout<<t<<endl;
		else if(t==k-1)	cout<<t+1<<endl;
		else			cout<<t+2<<endl;
		fz(i,1,t){
			cout<<cyc[i].size()<<endl;
			foreach(it,cyc[i])	cout<<*it<<" ";
			puts("");
		}
		int sum=0;
		if(t!=k){
			fz(i,t+1,k)	sum+=cyc[i].size();
			cout<<sum<<endl;
			fz(i,t+1,k)	foreach(it,cyc[i])	cout<<*it<<" ";
			if(t!=k-1){
				puts("");
				cout<<k-t<<endl;
				fd(i,k,t+1)	cout<<cyc[i][0]<<" ";
			}
		}
	}
	return 0;
}
/*
6 5
1 2 4 3 6 5
*/