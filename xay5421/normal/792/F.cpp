// author: xay5421
// created: Tue Sep 28 19:25:57 2021
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
using LL=long long;
int n;
LL m;
struct node{
	int x;
	mutable int y;
	bool operator<(const node&k)const{
		return x<k.x;
	}
};
set<node>S;
void ps(int x,int y){
	auto it=S.lower_bound((node){x,0});
	if(it!=S.end()&&it->x==x){
		it->y=max(it->y,y);
	}else{
		it=S.insert((node){x,y}).first;
		if(next(it)!=S.end()&&1LL*(next(it)->y-prev(it)->y)*(x-prev(it)->x)+1LL*prev(it)->y*(next(it)->x-prev(it)->x)>=1LL*y*(next(it)->x-prev(it)->x)){
			S.erase(it);
			return;
		}
		if(prev(it)->y>=it->y){
			S.erase(it);
			return;
		}
	}
	if(it==S.end())return;
	while(1){
		if(next(it)==S.end())break;
		auto k1=next(it);
		if(k1->y<=it->y){
			S.erase(k1);
			continue;
		}
		if(next(k1)==S.end())break;
		auto k2=next(k1);
		if(1LL*(k2->y-k1->y)*(k1->x-it->x)>=1LL*(k1->y-it->y)*(k2->x-k1->x)){
			S.erase(k1);
		}else break;
	}
	while(1){
		if(it==S.begin())break;
		auto k1=prev(it);
		if(k1==S.begin())break;
		auto k2=prev(k1);
		if(1LL*(k2->y-k1->y)*(k1->x-it->x)<=1LL*(k1->y-it->y)*(k2->x-k1->x)){
			S.erase(k1);
		}else break;
	}
}
int cmp(int t,int h){
	auto it=S.lower_bound((node){(int)min(1000005LL,(m+t-1)/t),0});
	if(it==S.end()){
		--it;
		if(it==S.begin())return 0;
		//D("k=%.5f %.5f\n",1.*(it->y-prev(it)->y)/(it->x-prev(it)->x),1.*(it->y-prev(it)->y)/(it->x-prev(it)->x)*(1.*m/t-it->x)+it->y);
		return 1LL*it->y*t>=h;
	}
	if(1LL*(it->y-prev(it)->y)*(m-1LL*it->x*t)+1LL*it->y*(it->x-prev(it)->x)*t>=1LL*h*(it->x-prev(it)->x)){
		return 1;
	}
	return 0;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%lld",&n,&m);
	int lst=0;
	S.insert((node){0,0});
	rep(i,1,n){
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		((x+=lst)%=1000000)+=1;
		((y+=lst)%=1000000)+=1;
		if(opt==1){
			swap(x,y);
			ps(x,y);
		}else{
			if(cmp(x,y)){
				puts("YES");
				lst=i;
			}else{
				puts("NO");
			}
		}
	}
	return 0;
}