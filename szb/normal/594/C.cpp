#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define maxn 100010
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll val1[maxn],val2[maxn],val3[maxn],val4[maxn],cho1[maxn],cho2[maxn],cho3[maxn],cho4[maxn],n,k,ans=1e18+1;
map<ll,bool>mp;
struct data{	ll x,y,id;	}p[maxn];
bool cmp1(data a,data b){	return a.x<b.x;	}
bool cmp2(data a,data b){	return a.x>b.x;	}
bool cmp3(data a,data b){	return a.y<b.y;	}
bool cmp4(data a,data b){	return a.y>b.y;	}
int main(){
	n=read();	k=read();
	For(i,1,n)	p[i].x=read(),p[i].y=read(),p[i].x=read()+p[i].x,p[i].y=read()+p[i].y,p[i].id=i;	k++;
//	For(i,1,n)	printf("%lld %lld\n",p[i].x,p[i].y);
	sort(p+1,p+n+1,cmp1);	For(i,1,k)	cho1[i]=p[i].id,val1[i]=p[i].x;
	sort(p+1,p+n+1,cmp2);	For(i,1,k)	cho2[i]=p[i].id,val2[i]=p[i].x;
	sort(p+1,p+n+1,cmp3);	For(i,1,k)	cho3[i]=p[i].id,val3[i]=p[i].y;
	sort(p+1,p+n+1,cmp4);	For(i,1,k)	cho4[i]=p[i].id,val4[i]=p[i].y;	--k;
	For(t1,0,k)	For(t2,0,k)	For(t3,0,k)	For(t4,0,k){
		mp.clear();	ll ned=0;
		For(a,1,t1)	if (!mp[cho1[a]])	mp[cho1[a]]=1,++ned;
		For(a,1,t2)	if (!mp[cho2[a]])	mp[cho2[a]]=1,++ned;
		For(a,1,t3)	if (!mp[cho3[a]])	mp[cho3[a]]=1,++ned;
		For(a,1,t4)	if (!mp[cho4[a]])	mp[cho4[a]]=1,++ned;
		if (ned<=k){
			ans=min(ans,(max((val2[t2+1]-val1[t1+1]+1)/2,1LL)*max((1+val4[t4+1]-val3[t3+1])/2,1LL)));
		}else	break;
	}
	writeln(ans);
}
/*
nk
n-k
*/