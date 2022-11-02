#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define ull unsigned long long
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int M=1<<21|2,N=1000005,inf=1e9;
int n,k,ti,in[N],out[N],a[N],tr[M],lazy[M];
vector<int> v[N];
priority_queue<PI,vector<PI>,greater<PI> > q;
void push_up(int nod){
	tr[nod]=max(tr[nod<<1],tr[nod<<1|1])+lazy[nod];
}
void cao(int nod,int de){
	tr[nod]+=de; lazy[nod]+=de;
}
void insert(int l,int r,int i,int j,int de,int nod){
	if(l==i&&r==j){
		cao(nod,de); return;
	}
	int mid=(l+r)>>1;
	if(j<=mid)insert(l,mid,i,j,de,nod<<1);
	else if(i>mid)insert(mid+1,r,i,j,de,nod<<1|1);
	else{
		insert(l,mid,i,mid,de,nod<<1); insert(mid+1,r,mid+1,j,de,nod<<1|1);
	}
	push_up(nod);
}
void dfs(int p){
	in[p]=++ti;
	for(auto i:v[p])dfs(i);
	out[p]=ti;
}
int main(){
	n=read(),k=read(); 
	for(int i=1;i<=n;i++){
		a[i]=read();
		while(q.size()&&q.top().first<a[i]){
			v[i].push_back(q.top().second); q.pop();
		}
		q.push(mp(a[i],i));
	}
	for(int i=n;i;i--)if(!in[i])dfs(i); 
	for(int i=1;i<k;i++){
		insert(1,n,in[i],out[i],1,1);  //cout<<in[i]<<" "<<out[i]<<" "<<tr[1]<<endl;
	}
	for(int i=k;i<=n;i++){
		insert(1,n,in[i],out[i],1,1);
		wri(tr[1]);
		insert(1,n,in[i-k+1],in[i-k+1],-inf,1);
	}
}