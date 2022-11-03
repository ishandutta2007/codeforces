#include<queue>
#include<ctime>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#include<ctime>
#define ll int
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define ld double
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=5010;	map<string,ll>mp;	string s;
ll answ[N][2],L[N],R[N],a[5010][1010],ans[N][2],typ[N],n,m;
int main(){
//	freopen("a.in","r",stdin);
	n=read();	m=read();
	For(i,1,n){
		cin>>s;	mp[s]=i;
		cin>>s;	cin>>s;
		if (s[0]=='0'||s[0]=='1'){	typ[i]=1;	For(j,0,m-1)	a[i][j]=s[j]-'0';	continue;	}
		if (s[0]=='?')	L[i]=0;	else	L[i]=mp[s];
		cin>>s;
		if (s[0]=='X')	typ[i]=2;
		else if (s[0]=='O')	typ[i]=3;
		else if (s[0]=='A')	typ[i]=4;
		cin>>s;
		if (s[0]=='?')	R[i]=0;	else	R[i]=mp[s];
	}
	For(i,0,m-1){
		memset(ans,0,sizeof ans);
		For(k,1,n)	if (typ[k]==1)	ans[k][0]=ans[k][1]=a[k][i];
		else{
			ll x0=0,y0=0,x1=0,y1=0;
			if (L[k])	x0+=ans[L[k]][0],x1+=ans[L[k]][1];	else	x1=1;
			if (R[k])	y0+=ans[R[k]][0],y1+=ans[R[k]][1];	else	y1=1;
			if (typ[k]==2)	ans[k][0]=x0^y0,ans[k][1]=x1^y1;
			if (typ[k]==3)	ans[k][0]=x0|y0,ans[k][1]=x1|y1;
			if (typ[k]==4)	ans[k][0]=x0&y0,ans[k][1]=x1&y1;
		}ll zero=0,one=0;
		For(k,1,n)	zero+=ans[k][0],one+=ans[k][1];
		answ[i][0]=zero>one;
		answ[i][1]=zero<one;
	}
	For(i,0,m-1)	putchar(answ[i][0]+'0');	puts("");
	For(i,0,m-1)	putchar(answ[i][1]+'0');
}
/*
3 3
a := 101
b := 011
c := ? XOR b
*/