#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,a[MAXN+5],b[MAXN+5],c[MAXN+5],d[MAXN+5];
int key[MAXN*2+5],cnt=0,uni[MAXN*2+5],num=0;
set<pii> st[MAXN*2+5];
void insert(int x,int y,int z){
	for(int i=x;i<=num;i+=(i&(-i))) st[i].insert(mp(y,z));
}
void del(int x,int y,int z){
	for(int i=x;i<=num;i+=(i&(-i))) st[i].erase(st[i].find(mp(y,z)));
}
vector<int> query(int x,int y){
	vector<int> ret;
	for(int i=x;i;i&=(i-1)){
		set<pii>::iterator t=st[i].lower_bound(mp(y+1,0));
		for(set<pii>::iterator it=st[i].begin();it!=t;++it){
			ret.pb(it->se);
		}
	} return ret;
}
int dis[MAXN+5],from[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		key[++cnt]=a[i];key[++cnt]=c[i];
	} key[++cnt]=0;sort(key+1,key+cnt+1);key[0]=-1;
	for(int i=1;i<=cnt;i++) if(key[i]!=key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
		c[i]=lower_bound(uni+1,uni+num+1,c[i])-uni;
	}
	for(int i=1;i<=n;i++) insert(a[i],b[i],i);
	memset(dis,-1,sizeof(dis));queue<int> q;
	vector<int> v=query(1,0);
	for(int i=0;i<v.size();i++) dis[v[i]]=1,q.push(v[i]),del(a[v[i]],b[v[i]],v[i]);
	while(!q.empty()){
		int x=q.front();q.pop();v=query(c[x],d[x]);
		for(int i=0;i<v.size();i++){
			int t=v[i];dis[t]=dis[x]+1;from[t]=x;q.push(t),del(a[t],b[t],t);
		}
	}
	if(dis[n]==-1) printf("-1\n");
	else{
		printf("%d\n",dis[n]);vector<int> v;
		for(int i=n;i;i=from[i]) v.pb(i);
		reverse(v.begin(),v.end());
		for(int i=0;i<v.size();i++) printf("%d ",v[i]);
	}
	return 0;
}