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
const int N=100005,B=350;
int n,Q,a[N];
struct DS{
	vector<deque<int> >a;
	int size(){return a.empty()?0:(SZ(a)-1)*B+SZ(a.back());}
	void push(int);
	void pop(int);
	int ask(int);
	int query(int);
};
struct DS2{
	int val[N],sum[N/B+5];
	void push(int x){
		val[x]+=1;
		sum[x/B]+=1;
	}
	void pop(int x){
		val[x]-=1;
		sum[x/B]-=1;
	}
	int ask(int x){
		int ret=0;
		rep(i,0,x/B-1)ret+=sum[i];
		rep(i,x/B*B,x-1)ret+=val[i];
		return ret;
	}
}bin[B];
map<int,DS>ds;
void DS::push(int x){
	if(a.empty()){
		a.push_back({x});
	}else{
		int pos=SZ(a)-1;
		rep(i,0,SZ(a)-1){
			if(x>=a[i][0]){
				pos=i;
			}
		}
		a[pos].insert(lower_bound(a[pos].begin(),a[pos].end(),x),x);
		rep(i,pos,SZ(a)-2){
			a[i+1].push_front(a[i].back());
			a[i].pop_back();
		}
		if(SZ(a.back())>B){
			a.push_back({a[SZ(a)-1].back()});
			a[SZ(a)-2].pop_back();
		}
	}
}
void DS::pop(int x){
	assert(!a.empty());
	int pos=SZ(a)-1;
	rep(i,0,SZ(a)-1){
		if(x>=a[i][0]){
			pos=i;
		}
	}
	a[pos].erase(lower_bound(a[pos].begin(),a[pos].end(),x));
	rep(i,pos+1,SZ(a)-1){
		a[i-1].push_back(a[i].front());
		a[i].pop_front();
	}
	if(a.back().empty())a.pop_back();
}
int DS::ask(int x){
	rep(i,0,SZ(a)-1){
		DD(x,i,SZ(a[i]));
		if(x>=a[i][0]&&x<=a[i].back()){
			D("!!\n");
			return i*B+(lower_bound(a[i].begin(),a[i].end(),x)-a[i].begin());
		}
	}
	rep(i,0,SZ(a)-2)assert(a.at(i).back()<a.at(i+1).at(0));
	rep(i,0,SZ(a)-1){
		rep(j,0,SZ(a[i])-2)assert(a.at(i).at(j)<a.at(i).at(j+1));
	}
	assert(0);
}
int DS::query(int x){
	return a[x/B][x%B];
}
set<int>S;
void pops(DS&ds,int id){
	if(ds.a.empty())return;
	if(ds.size()>=B)S.erase(id);
	rep(i,0,min(B,SZ(ds.a[0]))-1){
		// D("pop %d\n",ds.a[0][i]);
		bin[i].pop(ds.a[0][i]);
	}
}
void pushs(DS&ds,int id){
	if(ds.a.empty())return;
	if(ds.size()>=B)S.insert(id);
	rep(i,0,min(B,SZ(ds.a[0]))-1){
		// D("push %d\n",ds.a[0][i]);
		bin[i].push(ds.a[0][i]);
	}
}
void change(int p,int v){
	pops(ds[a[p]],a[p]);
	ds[a[p]].pop(p);
	pushs(ds[a[p]],a[p]);
	a[p]=v;
	pops(ds[a[p]],a[p]);
	ds[a[p]].push(p);
	pushs(ds[a[p]],a[p]);
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n){
		DD(i);
		rd(a[i]),pops(ds[a[i]],a[i]),ds[a[i]].push(i),pushs(ds[a[i]],a[i]);
	}
	rd(Q);
	while(Q--){
		int opt;
		rd(opt);
		if(opt==1){
			int v,p;
			rd(v),rd(p);
			change(p,v);
		}else{
			int x,y;
			rd(x),rd(y);
			DD(opt,x,y);
			if(x==1){
				printf("%d\n",a[y]);
			}else if(x%2==0){
				printf("%d\n",ds[a[y]].ask(y)+1);
			}else{
				assert(ds.count(a[y]));
				int val=ds[a[y]].ask(y);
				D("!\n");
				if(val<B){
					D("!!\n");
					printf("%d\n",bin[val].ask(y)+1);
				}else{
					D("!!!\n");
					int ret=0;
					for(auto it=S.begin();it!=S.end();++it)if(val<ds[*it].size()){
						D("!!!!\n");
						ret+=ds[*it].query(val)<y;
					}
					printf("%d\n",ret+1);
				}
			}
		}
	}
	return 0;
}