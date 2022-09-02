#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=200005;
int n,m,Q;
set<pair<int,int> >S;
struct BIT{
	int t[N];
	int qry(int x){
		int y=0;
		for(int i=x;i<=n;i+=i&-i)y=max(y,t[i]);
		return y;
	}
	void upd(int x,int y){
		for(int i=x;i;i&=i-1)t[i]=max(t[i],y);
	}
}t,t_;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,0,Q-1){
		int x,y;
		scanf("%d%d",&x,&y);
		S.insert({x,y});
	}
	queue<tuple<int,int,int> >que;
	que.emplace(1,1,0);
	while(!que.empty()){
		int x,y,z;
		tie(x,y,z)=que.front();
		que.pop();
		if(x<=n){
			if(t.qry(x)>=y){
				continue;
			}
			t.upd(x,y);
		}
		if(y<=m){
			if(t_.qry(y)>=x){
				continue;
			}
			t_.upd(y,x);
		}
		int now=S.count({x,y});
		if(x>=n&&x+y+now>=m){
			printf("%d\n",z+1);
			return 0;
		}
		if(x+y+now>=n&&y>=m){
			printf("%d\n",z+1);
			return 0;
		}
		if(x<y){
			que.emplace(min(n,x+y+now),y,z+1);
			que.emplace(x,min(m,x+y+now),z+1);
		}else{
			que.emplace(x,min(m,x+y+now),z+1);
			que.emplace(min(n,x+y+now),y,z+1);
		}
	}
	return 0;
}