#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_set>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_ai 1000000
#define max_n 150000
#define max_dn 300000//n*2
vector<int>v[max_ai+1];
int a[max_n+1],p[max_n+1];
int find(int&x){
	return x==p[x]?x:(x=find(p[x]));
}
unordered_set<long long>st;
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(int i=1; i<=n; ++i){
		p[i]=i;
		int x=a[i];
		for(int j=2,ed=sqrt(x); j<=ed; ++j){
			if(!(x%j)){
//				printf("%d\n",j);
				v[j].push_back(i);
				for(x/=j; !(x%j); x/=j);
				ed=sqrt(x);
			}
		}
		if(x>1)
			v[x].push_back(i);
	}
//	puts("asdf");
	for(int i=2; i<=max_ai; ++i)
		if(v[i].size()>=2){
//			printf("*%d\n",i);
			int u=*v[i].begin();
//			printf(" %d\n",u);
			find(u);
			for(auto it=v[i].end(),ed=v[i].begin(); --it!=ed; ){
				int v=*it;
//				printf(" %d\n",v);
				if(u!=find(v))
					p[v]=u;
//				printf("&^%d\n",p[2]);
			}
		}
//	puts("asdf");
	for(int i=1; i<=n; ++i){
		int u=i;
//		printf(" %d:%d\n",i,p[i]);
		find(u);
//		printf("%d:%d\n",i,u);
		int x=a[i]+1;
		int buf[10],cnt=0;
		for(int j=2,ed=sqrt(x); j<=ed; ++j){
//			printf("%d\n",x);
			if(!(x%j)){
//				puts("qaewr");
				if(!v[j].empty()){
					int now=*v[j].begin();
					find(now);
					buf[++cnt]=now;
				}
//				puts("fda");
				for(x/=j; !(x%j); x/=j)/*printf("%d\n",x)*/;
				ed=sqrt(x);
			}
		}
		if(!v[x].empty()){
			int now=*v[x].begin();
			find(now);
			buf[++cnt]=now;
		}
		buf[0]=u;
		sort(buf,buf+cnt+1);
		for(int i=0; i<cnt; ++i)
			for(int j=i; ++j<=cnt; )
				st.insert(ll(buf[i])*n+buf[j]-1);
	}
//	puts("asdf");
	for(int i=q,x,y; i; --i){
		scanf("%d%d",&x,&y);
		find(x),find(y);
		if(x==y){
			puts("0");
			continue;
		}
		if(x<y){
			if(st.count(ll(x)*n+y-1)){
				puts("1");
				continue;
			}
		}
		else{
			if(st.count(ll(y)*n+x-1)){
				puts("1");
				continue;
			}
		}
		puts("2");
	}
	return 0;
}