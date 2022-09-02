#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int n;

vector<int>p;
#ifdef xay5421
vector<int>ans;
int q_cnt;
int query(vector<int>v){
	++q_cnt;
	rep(i,0,n-1)v[i]^=p[i];
	int tot=0;
	rep(i,0,n-1)tot+=v[i]==ans[i];
	return tot;
}
#else
int query(vector<int>v){
	rep(i,0,n-1){
		putchar(v[i]^p[i]?'T':'F');
	}
	putchar('\n');
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
#endif

vector<int>v;
int w;
vector<tuple<int,int,int> >todo;
vector<int>new_pos;
void solve(vector<int>pos,int cnt){ // 
	if(cnt<SZ(pos)-cnt){
		each(i,pos)v[i]^=1;
		w-=cnt;
		cnt=SZ(pos)-cnt;
		w+=cnt;
	}
	if(cnt==SZ(pos)){
		return;
	}
	if(SZ(pos)==2){
		todo.emplace_back(pos[0],pos[1],v[pos[0]]^v[pos[1]]^1);
		new_pos.pb(pos[0]);
		return;
	}
	
	vector<int>pos_l,pos_r;
	rep(i,0,(SZ(pos)-1)/2)pos_l.pb(pos[i]);
	rep(i,(SZ(pos)-1)/2+1,SZ(pos)-1)pos_r.pb(pos[i]);
	
	vector<int>v0(v);
	each(i,pos_l)v0[i]^=1;
	
	int w0=query(v0);
	int dt=w0-w;
	
	int cnt_l=(SZ(pos_l)-dt)/2;
	solve(pos_l,cnt_l);
	solve(pos_r,cnt-cnt_l);
}
int main(){
	scanf("%d",&n);
#ifdef xay5421
	ans.assign(n,0);
	rep(i,0,n-1)ans[i]=rng()&1?1:0;
#endif
	p.assign(n,0);
	rep(i,0,n-1)p[i]=rng()&1?1:0;
	v.assign(n,0);
	rep(i,0,n-1)v[i]=rng()&1?1:0;
	w=query(v);
	vector<int>pos;
	rep(i,0,n-1)pos.pb(i);
	while(!pos.empty()){
		new_pos.clear();
		vector<int>v0(v);
		each(x,pos){
			v0[x]^=1;
		}
		int w0=query(v0);
		int dt=w0-w;
		solve(pos,(SZ(pos)-dt)/2);
		pos=new_pos;
	}
	per(i,SZ(todo)-1,0){
		int x,y,z;
		tie(x,y,z)=todo[i];
		v[y]=v[x]^z;
	}
	query(v);
#ifdef xay5421
	rep(i,0,n-1)assert((v[i]^p[i])==ans[i]);
	D("q_cnt=%d\n",q_cnt);
#endif
	return 0;
}