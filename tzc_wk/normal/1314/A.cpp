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
int n=read();
pii a[200005];
map<int,int> cnt;
int l[200005],r[200005],num=0;
signed main(){
	fz(i,1,n)	a[i].fi=read(),cnt[a[i].fi]++;
	fz(i,1,n)	a[i].se=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;){
		int sum=0;
		int cur=i;
		while(cur<=n){
			sum++;
			if(cur==n)	break;
			if(a[cur+1].fi>(a[i].fi+sum-1))	break;
			cur++;
		}
		l[++num]=i;
		r[num]=cur;
		i=cur+1;
	}
	int ans=0;
	fz(i,1,num){
		fz(j,l[i],r[i])	ans-=a[j].fi*a[j].se;
		map<int,bool> used;
		int _l=a[l[i]].fi,_r=_l+r[i]-l[i],cur=l[i];
//		cout<<_l<<" "<<_r<<endl;
		priority_queue<int> pq;
		fz(j,_l,_r){
			while(a[cur].fi<=j&&cur<=r[i]){
				pq.push(a[cur].se);
				cur++;
			}
			ans+=j*pq.top();
			pq.pop();
		}
	}
	print(ans);eoln;
	return 0;
}