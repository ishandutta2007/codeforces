#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef const int& ci;
void test(){
	int n,q;
	scanf("%d%d",&n,&q);
	set<pair<int,int> >a,b;
	b.insert(pii(0,0));
	b.insert(pii(n+1,n+1));
	for(int i=1; i<=q; ++i){
		int op,l,r,x;
		scanf("%d",&op);
		if(op==0){
			scanf("%d%d%d",&l,&r,&x);
			if(x==0){
				while(1){
					auto tmp=b.lower_bound(pii(l,0));
					if(tmp->first<=min(n,r+1)){
						r=max(r,tmp->second);
						b.erase(tmp);
					}
					else
						break;
				}
				while(1){
					auto tmp=prev(b.lower_bound(pii(l,0)));
					if(tmp->second>=max(1,l-1)){
						l=min(l,tmp->first);
						r=max(r,tmp->second);
						b.erase(tmp);
					}
					else
						break;
				}
				b.insert(pii(l,r));
			}
			else{
				while(1){
					auto tmp=a.lower_bound(pii(l+1,0));
					if(tmp!=a.begin()&&prev(tmp)->second>=r)
						a.erase(prev(tmp));
					else
						break;
				}
				auto tmp=a.lower_bound(pii(l,0));
				if(tmp==a.end()||tmp->second>r)
					a.insert(pii(l,r));
			}
		}
		else{
			scanf("%d",&x);
			auto tmp=b.lower_bound(pair<int,int>(x,0));
			if(prev(tmp)->second>=x||tmp->first==x){
				puts("NO");
				continue;
			}
			int l=prev(tmp)->second!=x-1?x:prev(tmp)->first,r=x;
			while(l<r){
				int mid=(l+r)>>1;
				auto ttmp=a.lower_bound(pii(mid,0));
				if(ttmp!=a.end()&&ttmp->second<x)
					l=mid+1;
				else
					r=mid;
			}
//			int l=prev(tmp)->first;
			auto ttmp=a.lower_bound(pii(l,0));
//			while(ttmp!=a.end()&&ttmp->second<x)
//				ttmp=a.lower_bound(pii(ttmp->first+1,0));
			if(ttmp==a.end()||ttmp->first>x||ttmp->second<x||ttmp->second>tmp->second||tmp->first!=x+1&&ttmp->second!=x){
				puts("N/A");
				continue;
			}
			puts("YES");
		}
//		printf("%d:\n",i);
//		for(auto x:a)
//			printf(" a(%d,%d)\n",x.first,x.second);
//		for(auto x:b)
//			printf(" b(%d,%d)\n",x.first,x.second);
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}