#include<queue>
#include<ctime>
#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<memory.h>
#include<map>
#include<ctime>
#include<algorithm>
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
#define F first
#define S i
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
const ll N=200010;
ll answ=1e18,f[N],q[4][N],st[10],v[N],sum,ans,n,k,m,s1,s2;
bool add(){
	ll cho=1e10;
	if (q[1][0]>st[1])	cho=min(cho,q[1][st[1]+1]);
	if (q[2][0]>st[2])	cho=min(cho,q[2][st[2]+1]);
	if (q[3][0]>st[3])	cho=min(cho,q[3][st[3]+1]);
	if (cho==1e10)	return 0;
	sum++;	ans+=cho;
	if (cho==q[1][st[1]+1])	st[1]++;
	else if (cho==q[2][st[2]+1])	st[2]++;
	else if (cho==q[3][st[3]+1])	st[3]++;
	else	puts("LZH_ak");
	return 1;
}
bool del(){
	ll cho=0;
	if (st[1]>k)	cho=max(cho,q[1][st[1]]);
	if (st[2]>k)	cho=max(cho,q[2][st[2]]);
	if (st[3])		cho=max(cho,q[3][st[3]]);
	if (cho==0)	return 0;
	sum--;	ans-=cho;
	if (cho==q[1][st[1]]&&(st[1]>k))	st[1]--;
	else if (cho==q[2][st[2]]&&(st[2]>k))	st[2]--;
	else if (cho==q[3][st[3]]&&st[3])	st[3]--;
	else	puts("lzh_AK");
	return 1;
}
bool tiao_zhen(){
	ll cho1=0,cho2=1e10,c1,c2;
	if (st[1]>k)	cho1=max(cho1,q[1][st[1]]);
	if (st[2]>k)	cho1=max(cho1,q[2][st[2]]);
	if (st[3])		cho1=max(cho1,q[3][st[3]]);
	if (q[1][0]>st[1])	cho2=min(cho2,q[1][st[1]+1]);
	if (q[2][0]>st[2])	cho2=min(cho2,q[2][st[2]+1]);
	if (q[3][0]>st[3])	cho2=min(cho2,q[3][st[3]+1]);
	if (cho1<=cho2)	return 0;
	if (cho1==q[1][st[1]]&&(st[1]>k))	st[1]--;
	else if (cho1==q[2][st[2]]&&(st[2]>k))	st[2]--;
	else if (cho1==q[3][st[3]]&&st[3])	st[3]--;
	if (cho2==q[1][st[1]+1])	st[1]++;
	else if (cho2==q[2][st[2]+1])	st[2]++;
	else if (cho2==q[3][st[3]+1])	st[3]++;
	ans-=cho1-cho2;
	return 1;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	n=read();	m=read();	k=read();
	if (m<k)	return puts("-1"),0;
	For(i,1,n)	v[i]=read();
	s1=read();
	For(i,1,s1)	f[read()]^=1;
	s2=read();
	For(i,1,s2)	f[read()]^=2;
	For(i,1,n)	if (f[i]==3||f[i]==0)	f[i]=3-f[i];
	For(i,1,n)	q[f[i]][++q[f[i]][0]]=v[i];
	For(i,0,3)	sort(q[i]+1,q[i]+q[i][0]+1);
	For(i,1,min(q[1][0],k))	ans+=q[1][i],st[1]=i;
	For(i,1,min(q[2][0],k))	ans+=q[2][i],st[2]=i;
	sum=st[1]+st[2];
	while(sum<m&&add());
	if (st[1]>=k&&st[2]>=k&&sum==m)answ=min(ans,answ);
	For(i,1,q[0][0]){
		sum++;	ans+=q[0][++st[0]];	k=max(k-1,0LL);
		while(sum>m&&del());
		while(sum<m&&add());
		while(tiao_zhen());
		if (sum==m&&st[1]>=k&&st[2]>=k)	answ=min(answ,ans);
	}
	writeln(answ==1e18?-1:answ);
}/*

niciArkadyMasha
mmkArkadykMasha
-1
1 <= n <= 2e5, 1 <= m <= n, 1 <= k <= n.
1 <= ci <= 1e9.
*/