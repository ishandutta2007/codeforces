#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	vector<tuple<int,int> >a(n),b(m);
	rep(i,0,n-1){
		scanf("%d%d",&get<0>(a[i]),&get<1>(a[i]));
	}
	rep(i,0,m-1){
		scanf("%d%d",&get<0>(b[i]),&get<1>(b[i]));
	}
	auto calc=[&](tuple<int,int>lhs,tuple<int,int>rhs){
		return (get<0>(lhs)==get<0>(rhs))+(get<0>(lhs)==get<1>(rhs))+(get<1>(lhs)==get<0>(rhs))+(get<1>(lhs)==get<1>(rhs));
	};
	vector<int>cntx(n),cnty(m);
	set<int>S;
	rep(x,0,n-1)rep(y,0,m-1){
		if(calc(a[x],b[y])==1){
			auto&lhs=a[x];
			auto&rhs=b[y];
			if(get<0>(lhs)==get<0>(rhs)||get<0>(lhs)==get<1>(rhs))S.insert(get<0>(lhs));
			if(get<1>(lhs)==get<0>(rhs)||get<1>(lhs)==get<1>(rhs))S.insert(get<1>(lhs));
		}
	}
	if(SZ(S)==1){
		printf("%d\n",*S.begin());
	}else{
		rep(x,0,n-1){
			set<int>SS;
			rep(y,0,m-1){
				if(calc(a[x],b[y])==1){
					auto&lhs=a[x];
					auto&rhs=b[y];
					if(get<0>(lhs)==get<0>(rhs)||get<0>(lhs)==get<1>(rhs))SS.insert(get<0>(lhs));
					if(get<1>(lhs)==get<0>(rhs)||get<1>(lhs)==get<1>(rhs))SS.insert(get<1>(lhs));
				}
			}
			if(SZ(SS)>1){
				puts("-1"),exit(0);
			}
		}
		rep(y,0,m-1){
			set<int>SS;
			rep(x,0,n-1){
				if(calc(a[x],b[y])==1){
					auto&lhs=a[x];
					auto&rhs=b[y];
					if(get<0>(lhs)==get<0>(rhs)||get<0>(lhs)==get<1>(rhs))SS.insert(get<0>(lhs));
					if(get<1>(lhs)==get<0>(rhs)||get<1>(lhs)==get<1>(rhs))SS.insert(get<1>(lhs));
				}
			}
			if(SZ(SS)>1){
				puts("-1"),exit(0);
			}
		}
		puts("0");
	}
	return 0;
}