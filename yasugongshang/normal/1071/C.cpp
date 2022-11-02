#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
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
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
const int N=100005;
int n,a[N];
vector<pair<pair<int,int>,int> > ans;
void s(int x,int y,int z){
	if(y-x!=z-y)while(1);
	ans.push_back(mp(mp(x,y),z));
	a[x]^=1; a[y]^=1; a[z]^=1;
	//or(int i=1;i<=n;i++)wri(a[i]); puts("");
}
void gao(int l,int r){
	if((r-l)&1)return;
	s(l,(l+r)/2,r);
}
int ch(int l,int r){
	return a[l]*4+a[l+1]*2+a[r];
}
int get(int l,int r){
	if(ch(l,r)==1)return r;
	if(ch(l,r)==2)return r-1;
	if(ch(l,r)==4)return r-2;
	return 0;
}
const int inf=100;
vector<int> v;
map<vector<int>,int> M;
vector<int> q[10000];
int bfs(){
	int l=1,r=1;
	q[1].resize(n+1);
	while(l<=r){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=2*j-i; if(t>n)break;
				vector<int> zs=q[l];
				zs[i]^=1; zs[j]^=1; zs[t]^=1; 
				if(!M.count(zs)){q[++r]=zs; M[zs]=M[q[l]]+1;}
			}
		}
		l++;
	}
	return M.count(v)?M[v]:inf;
}
void solve(vector<int> v){
	if(M[v]==0){
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t=2*j-i; if(t>n)break;
			vector<int> zs=v;
			zs[i]^=1; zs[j]^=1; zs[t]^=1;
			if(M[zs]+1==M[v]){s(i,j,t); solve(zs); return;}
		}
	}
}
bool baoz(int l,int r){
	if(ch(l,r)==7){s(l,l+1,l+2); return 1;}
	else if(ch(l,r)==5){s(l,l+2,l+4); return 1;}
	else if(ch(l,r)==3){s(r-1,r,r+1); return 1;}
	else if(ch(l,r)==0)return 1;
	return 0;
}
bool baoy(int l,int r){
	if(ch(l,r)==7){s(l,l+1,l+2); return 1;}
	else if(ch(l,r)==5){s(r-4,r-2,r); return 1;}
	else if(ch(l,r)==6){s(l-1,l,l+1); return 1;}
	else if(ch(l,r)==0)return 1;
	return 0;
}
void bao(int x){
	if(x+6<=n){
		s(x,x+3,x+6);
		s(x+3,x+4,x+5);
		s(x+4,x+5,x+6);
	}else{
		s(x-6,x-3,x);
		s(x-5,x-4,x-3);
		s(x-6,x-5,x-4);
	}
}
void print(){
	cout<<ans.size()<<endl;
	for(auto i:ans){
		wri(i.first.first); wri(i.first.second); writeln(i.second);
	}
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(n<13){
		v.resize(n+1);  
		for(int i=1;i<=n;i++)v[i]=a[i];
		if(bfs()>=inf){puts("NO"); return 0;};
		puts("YES");
		solve(v);
		print();
		return 0;
	}
	puts("YES");
	int l=1,r=n;
	while(l+8<=r){
		if(baoz(l,l+2))l+=3;
		else if(baoy(r-2,r))r-=3;
		else{
			if(ch(l,l+2)==6&&ch(r-2,r)==3){
 				if((r-l)&1){gao(l,r-1); gao(l+1,r);}
 				else {gao(l,r); gao(l+1,r-1);}
 				l+=3; r-=3;
			}else if(get(l,l+2)){
				int t=get(l,l+2);
				gao(t,r); gao(t,r-1);
				l+=3;
			}else if(get(r-2,r)){
				int t=get(r-2,r);
				gao(l,t); gao(l+1,t);
				r-=3;
			}
		}//cout<<l<<" wzp "<<r<<endl;for(int i=1;i<=n;i++)wri(a[i]); puts("");
	}
	for(int i=l;i+2<=r;i++)if(a[i])gao(i,i+2);
	if(a[r]==1&&a[r-1]==1){
		gao(r-2,r); bao(r-2);
	}else if(a[r]==1)bao(r);
	else  if(a[r-1])bao(r-1);
	print();
	if(ans.size()>n/3+12)while(1);
	for(int i=1;i<=n;i++)if(a[i])while(1);
}
/*
101001
1->2 2->1 0->3
*/