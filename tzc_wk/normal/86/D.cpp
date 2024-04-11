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
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define int long long
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
const int BLOCK_SZ=500;
int n,m,a[200005],blk,l[200005],r[200005],bel[200005];
struct query{
	int l,r,id;
	friend bool operator <(query a,query b){
		if(bel[a.l]!=bel[b.l])
			return bel[a.l]<bel[b.l];
		else if(bel[a.l]&1)
			return a.r<b.r;
		else
			return a.r>b.r;
	}
} q[200005];
int ans=0,cnt[1000005],len[200005];
inline void ins(int x){
	ans-=(cnt[a[x]]*cnt[a[x]]*a[x]);
	cnt[a[x]]++;
	ans+=(cnt[a[x]]*cnt[a[x]]*a[x]);
//	cout<<"ins "<<x<<" ans="<<ans<<endl;
}
inline void del(int x){
	ans-=(cnt[a[x]]*cnt[a[x]]*a[x]);
	cnt[a[x]]--;
	ans+=(cnt[a[x]]*cnt[a[x]]*a[x]);
}
int anss[50005];
signed main(){
	n=read();
	m=read();
	fz(i,1,n)	a[i]=read();
	blk=(n-1)/BLOCK_SZ+1;
	fz(i,1,blk){
		l[i]=(i-1)*BLOCK_SZ+1;
		r[i]=min(i*BLOCK_SZ,n);
		fz(j,l[i],r[i])	bel[j]=i;
	}
	fz(i,1,m){
		q[i].l=read();
		q[i].r=read();
		q[i].id=i;
		len[i]=q[i].r-q[i].l+1;
	}
	sort(q+1,q+m+1);
	int L=1,R=0;
	fz(i,1,m){
		while(L<q[i].l)	del(L++);
		while(L>q[i].l)	ins(--L);
		while(R<q[i].r)	ins(++R);
		while(R>q[i].r)	del(R--);
		anss[q[i].id]=ans;
	}
	fz(i,1,m){
		cout<<anss[i]<<endl;
	}
	return 0;
}