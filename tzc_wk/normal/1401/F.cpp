/*
Contest: Codeforces Round #665 (Div.2)
Problem: Codeforces Round #665 (Div.2) F
Author: tzc_wk
Time: 2020.8.21
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),q=read(),a[300005],fl=0;
int bit[300005],lg[300005];
inline void add(int x,int v){
	x++;for(int i=x;i<=300000;i+=(i&(-i))) bit[i]+=v;
}
inline int query(int x){
	x++;int sum=0;for(int i=x;i;i-=(i&(-i))) sum+=bit[i];return sum;
}
inline int query_(int l,int r){
	return query(r)-query(l-1);
}
inline int ask(int x){
	if(x==-1) return 0;
	if(x==0) return a[fl];
	int sum=a[fl^x];
	while(x){
		int t=x&(x-1),l=x&(-x);
		int _l=t^fl&(~(l-1)),_r=(t^fl)|(l-1);
		sum+=query_(_l,_r);
		x=t;
	}
	return sum;
}
signed main(){
	for(int i=0;i<(1<<n);i++) a[i]=read(),add(i,a[i]);
	for(int i=0;i<=n;i++) lg[1<<i]=i;
	while(q--){
		int opt=read();
		if(opt==1){
			int x=read(),k=read();x--;
			add(x^fl,-a[x^fl]);a[x^fl]=k;add(x^fl,a[x^fl]);
		}
		else if(opt==2){
			int k=read();fl^=((1<<k)-1);
		}
		else if(opt==3){
			int k=read();fl^=(1<<k);
		}
		else{
			int l=read(),r=read();l--;r--;cout<<ask(r)-ask(l-1)<<endl;
		}
	}
	return 0;
}