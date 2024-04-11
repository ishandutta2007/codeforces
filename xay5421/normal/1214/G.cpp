#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define SZ(x) ((int)(x).size())
using namespace std;
const int N=2005;
int n,m,Q,cnt[N],good;
bitset<N>b[N],tp;
struct cmp{
	bool operator()(const int&k1,const int&k2)const{return cnt[k1]^cnt[k2]?cnt[k1]<cnt[k2]:k1<k2;}
};
set<int,cmp>S;
set<pair<int,int> >T;
void ad(int k1,int k2){
	if((b[k1]&b[k2])!=b[k1])T.insert(make_pair(k1,k2));
}
void su(int k1,int k2){
	T.erase(make_pair(k1,k2));
}
void del(int k1){
	auto it=S.find(k1);
	if(it!=S.begin()){
		su(*prev(it),*it);
	}
	if(it!=--S.end()){
		su(*it,*next(it));
	}
	if(it!=S.begin()&&it!=--S.end()){
		ad(*prev(it),*next(it));
	}
	S.erase(k1);
}
void ins(int k1){
	auto it=S.insert(k1).X;
	if(it!=S.begin()){
		ad(*prev(it),*it);
	}
	if(it!=--S.end()){
		ad(*it,*next(it));
	}
	if(it!=S.begin()&&it!=--S.end()){
		su(*prev(it),*next(it));
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,n)S.insert(i);
	rep(i,1,Q){
		int a,l,r;
		scanf("%d%d%d",&a,&l,&r);
		tp.set();
		tp>>=N-(r-l+1);
		tp<<=l;
		del(a);
		b[a]^=tp;
		cnt[a]=b[a].count();
		ins(a);
		if(SZ(T)){
			int k1,k2;
			tie(k1,k2)=*T.begin();
			tp=b[k1]&b[k2];
			int p1=(tp^b[k1])._Find_first();
			int p2=(tp^b[k2])._Find_first();
			if(k1>k2)swap(k1,k2);
			if(p1>p2)swap(p1,p2);
			printf("%d %d %d %d\n",k1,p1,k2,p2);
		}else puts("-1");
	}
	return 0;
}