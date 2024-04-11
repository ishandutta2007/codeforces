#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,p,m;
struct data{
	int cost,time,id;
} x[100005];
inline bool cmp1(data x,data y){
	if(x.cost!=y.cost) return x.cost>y.cost;
	return x.time<y.time;
}
inline bool cmp2(data x,data y){
	return x.time>y.time;
}
struct node{
	int ch[2],val,sum,key,sz;
	inline void init(){ch[0]=ch[1]=val=sum=key=sz=0;}
} s[100005];
int cnt=0,root=0;
inline void init(){
	fz(i,0,cnt) s[i].init();
	cnt=root=0;
}
inline void pushup(int k){
	s[k].sum=s[s[k].ch[0]].sum+s[k].val+s[s[k].ch[1]].sum;
	s[k].sz=s[s[k].ch[0]].sz+1+s[s[k].ch[1]].sz;
}
inline void split_v(int k,int v,int &a,int &b){
	if(!k){a=b=0;return;}
	if(s[k].val<=v) a=k,split_v(s[k].ch[1],v,s[k].ch[1],b);
	else b=k,split_v(s[k].ch[0],v,a,s[k].ch[0]);
	pushup(k);
}
inline void split_s(int k,int rk,int &a,int &b){
	if(!k){a=b=0;return;}
	if(rk>s[s[k].ch[0]].sz) a=k,split_s(s[k].ch[1],rk-s[s[k].ch[0]].sz-1,s[k].ch[1],b);
	else b=k,split_s(s[k].ch[0],rk,a,s[k].ch[0]);
	pushup(k);
}
inline int merge(int a,int b){
	if(a==0||b==0) return a+b;
	if(s[a].key<s[b].key) return s[a].ch[1]=merge(s[a].ch[1],b),pushup(a),a;
	else return s[b].ch[0]=merge(a,s[b].ch[0]),pushup(b),b;
}
inline void insert(int x){
	cnt++;s[cnt].val=x;s[cnt].sum=x;s[cnt].sz=1;
	s[cnt].key=rand();s[cnt].ch[0]=s[cnt].ch[1]=0;
	int k1,k2;split_v(root,x,k1,k2);
	root=merge(merge(k1,cnt),k2);
}
//inline void debug(int x){
//	if(!x) return;
//	debug(s[x].ch[0]);
//	printf("node %d %d %d %d %d\n",x,s[x].ch[0],s[x].ch[1],s[x].val,s[x].sz);
//	debug(s[x].ch[1]);
//}
int mx[100005];
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),p=read(),m=read();
	fz(i,1,n) x[i].time=read(),x[i].cost=read(),x[i].id=i;
	sort(x+1,x+n+1,cmp1);
//	fz(i,1,n) cout<<x[i].cost<<" "<<x[i].time<<endl;
	fz(i,1,m) insert(x[i].time);
	mx[m]=s[root].sum;
	fz(i,m+1,n-(p-m)){
		insert(x[i].time);
		int k1,k2;split_s(root,i-m,k1,k2);
		mx[i]=s[k2].sum;
		root=merge(k1,k2);
	}
	int ans=0,ind=0;
	vector<int> t;
	fz(i,1,n-(p-m)) if(mx[i]>ans) ans=mx[i],ind=i;
	sort(x+1,x+ind+1,cmp2);
	fz(i,1,m) t.push_back(x[i].id);
	fz(i,ind+1,ind+(p-m)) t.push_back(x[i].id);
//	cout<<ans<<" "<<ind<<endl;
	sort(all(t));
	for(int i=0;i<t.size();i++) printf("%d ",t[i]);
	return 0;
}
/*
5 3 2
5 6
5 8
1 3
4 3
4 11

5 3 3
10 18
18 17
10 20
20 18
20 18

6 4 2
10 2
5 3
6 4
9 1
8 3
6 2
*/