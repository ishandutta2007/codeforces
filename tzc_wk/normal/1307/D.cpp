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
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),k=read(),a[200005],dist1[200005],dist2[200005],is[200005];
vector<int> g[200005];
inline void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,1});
	memset(dist1,63,sizeof(dist1));
	dist1[1]=0;
	while(!q.empty()){
		pair<int,int> p=q.top();q.pop();
		int x=p.se,sum=p.fi;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
			if(dist1[y]>dist1[x]+1){
				dist1[y]=dist1[x]+1;
				q.push({dist1[y],y});
			}
		}
	}
	q.push({0,n});
	memset(dist2,63,sizeof(dist2));
	dist2[n]=0;
	while(!q.empty()){
		pair<int,int> p=q.top();q.pop();
		int x=p.se,sum=p.fi;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i];
			if(dist2[y]>dist2[x]+1){
				dist2[y]=dist2[x]+1;
				q.push({dist2[y],y});
			}
		}
	}
}
int d1[200005],d2[200005];
pair<int,int> p[200005];
int bit[200005];
inline int lowbit(int x){
	return x&(-x);
}
inline void add(int x){
	for(int i=x;i<=n+1;i+=lowbit(i))	bit[i]++;
}
inline int query(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))	ans+=bit[i];
	return ans;
}
inline bool check(int mid){
	vector<pair<pair<int,int>,int> > qs;
	fz(i,1,k){
		qs.push_back({{mid-d2[i]+1,mid-d1[i]+1},i});
	}
	sort(qs.begin(),qs.end());reverse(qs.begin(),qs.end());
	memset(bit,0,sizeof(bit));
	int cnt=1;
//	for(int i=1;i<=k;i++)	cout<<p[i].fi<<" "<<p[i].se<<endl;
//	for(int i=0;i<qs.size();i++)	cout<<qs[i].fi.fi<<" "<<qs[i].fi.se<<endl;
	for(int i=0;i<qs.size();i++){
		int l1=qs[i].fi.fi,l2=qs[i].fi.se;
		while(p[cnt].fi>=l1-1&&cnt<=k)	add(p[cnt].se+1),cnt++;
		int num=query(n+1)-((l2<=1)?0:query(l2-1));
		if(num>1)	return 1;
		else if(num==1){
			int ind=qs[i].se;
			if(d1[ind]+1>=l1&&d2[ind]+1>=l2);
			else	return 1;
		}
	}
	return 0;
}
signed main(){
	fz(i,1,k)	a[i]=read(),is[a[i]]=1;
	bool flag=0;
	fz(i,1,m){
		int u=read(),v=read();
		g[u].push_back(v);
		g[v].push_back(u);
		if(is[u]&&is[v])	flag=1;
	}
	dijkstra();
//	if(flag)	return print(dist1[n]),eoln,0;
	fz(i,1,k)	d1[i]=dist1[a[i]],d2[i]=dist2[a[i]],p[i]={d1[i],d2[i]};
	sort(p+1,p+k+1);reverse(p+1,p+k+1); 
	int l=0,r=n,ans=0;
//	cout<<check(2)<<endl;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))	ans=mid,l=mid+1;
		else			r=mid-1;
	}
	ans++;
	if(ans>dist1[n])	ans=dist1[n];
	print(ans);
	return 0;
}