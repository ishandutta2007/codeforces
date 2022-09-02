#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>bool umin(T&x,const T&y){return y<x?x=y,1:0;}
template<class T>bool umax(T&x,const T&y){return x<y?x=y,1:0;}
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=300005;
int n,m,C,ans[N];
struct seg{
	int l,r,c;
	bool operator<(const seg&rhs)const{
		return c<rhs.c;
	}
}p[N];
struct node{
	int pos,sgn,id;
	bool operator<(const node&rhs)const{
		return pos<rhs.pos;
	}
}a[N*2];
struct node_q{
	int time,id;
	bool operator<(const node_q&rhs)const{
		return time<rhs.time;
	}
}qs[N];
int a0;
int nope,one[N],maxx[N];
map<pair<int,int>,int>two;
struct segTree{
	pair<int,int>mx[N*4];
	void upd(int k1){
		mx[k1]=max(mx[k1*2],mx[k1*2+1]);
	}
	void bud(int k1,int k2,int k3){
		if(k2==k3){
			mx[k1]={one[k2],k2};
			return;
		}
		int mid=(k2+k3)>>1;
		bud(k1*2,k2,mid),bud(k1*2+1,mid+1,k3);
		upd(k1);
	}
	void fix(int k1,int k2,int k3,int k4){
		if(k2==k3){
			mx[k1]={one[k2],k2};
			return;
		}
		int mid=(k2+k3)>>1;
		if(k4<=mid)fix(k1*2,k2,mid,k4);
		else fix(k1*2+1,mid+1,k3,k4);
		upd(k1);
	}
	pair<int,int>query(int k1,int k2,int k3,int k4,int k5){
		if(k2==k4&&k3==k5){
			return mx[k1];
		}
		int mid=(k2+k3)>>1;
		if(k5<=mid)return query(k1*2,k2,mid,k4,k5);
		else if(mid+1<=k4)return query(k1*2+1,mid+1,k3,k4,k5);
		else return max(query(k1*2,k2,mid,k4,mid),query(k1*2+1,mid+1,k3,mid+1,k5));
	}
}tr;
int calc(int x,int y){
	return one[x]+one[y]+two[minmax(x,y)];
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(C);
	rep(i,1,n){
		rd(p[i].l),rd(p[i].r),rd(p[i].c);
	}
	if(n==0)n=1;
	sort(p+1,p+n+1);
	rep(i,1,n){
		a[++a0]=(node){p[i].l,1,i};
		a[++a0]=(node){p[i].r,-1,i};
	}
	sort(a+1,a+a0+1);
	a[++a0]=(node){2000000005,1,n+1};
	rd(m);
	rep(i,1,m)rd(qs[i].time),qs[i].id=i;
	sort(qs+1,qs+m+1);
	tr.bud(1,1,n);
	int old_pos=0,cur_max=0;
	set<int>S;
	int j=1;
	rep(i,1,a0){
		int new_pos=a[i].pos;
		D("i=%d old_pos=%d new_pos=%d\n",i,old_pos,new_pos);
		int cur_len=new_pos-old_pos;
		if(S.empty()){
			nope+=cur_len;
		}else if(SZ(S)==1){
			int u=*S.begin();
			one[u]+=cur_len;
			maxx[u]+=cur_len;
			tr.fix(1,1,n,u);
			int remain=C-p[u].c;
			if(remain>=0){
				int pos=upper_bound(p+1,p+n+1,(seg){0,0,remain})-p-1;
				if(pos>u){
					int v=get<1>(tr.query(1,1,n,u+1,pos));
					int now=calc(u,v);
					umax(maxx[u],now);
					umax(maxx[v],now);
					umax(cur_max,now);
				}
				if(pos>=u)pos=u-1;
				if(pos>=1){
					int v=get<1>(tr.query(1,1,n,1,pos));
					int now=calc(u,v);
					umax(maxx[u],now);
					umax(maxx[v],now);
					umax(cur_max,now);
				}
				umax(cur_max,maxx[u]);
			}
		}else if(SZ(S)==2){
			int u=*S.begin();
			int v=*next(S.begin());
			pair<int,int>uv=minmax(u,v);
			if(two.find(uv)!=two.end()){
				two[uv]+=cur_len;
			}else{
				two[uv]=cur_len;
			}
			if(p[u].c+p[v].c<=C){
				int now=calc(u,v);
				umax(maxx[u],now);
				umax(maxx[v],now);
				umax(cur_max,now);
			}
		}
		D("cur_max=%d nope=%d\n",cur_max,nope);
		while(j<=m&&cur_max+nope>=qs[j].time){
			D("j=%d\n",j);
			ans[qs[j].id]=new_pos-(cur_max+nope-qs[j].time);
			++j;
		}
		if(a[i].sgn==1){
			S.insert(a[i].id);
		}else{
			S.erase(a[i].id);
		}
		old_pos=new_pos;
	}
	rep(i,1,m)pt(ans[i],'\n');
	return 0;
}