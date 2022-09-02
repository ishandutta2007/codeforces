#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int T;
void sol(){
	int n,m;
	scanf("%d%d",&n,&m);
	vector<vector<pair<int,int> > >g(n);
	vector<int>c(m);
	vector<vector<int> >edge(n,vector<int>(n,0));
	vector<vector<int> >f;
	auto ps1=[&](int x,int c){
		vector<int>v(m+1);
		v[x]=1,v[m]=c;
		f.pb(v);
	};
	auto ps2=[&](int x,int y,int z){
		vector<int>v(m+1);
		v[x]=v[y]=v[z]=1;
		f.pb(v);
	};
	rep(i,0,m-1){
		int u,v;
		scanf("%d%d%d",&u,&v,&c[i]);
		--u,--v;
		if(v<u)swap(u,v);
		if(c[i]!=-1){
			ps1(i,c[i]);
		}
		g[u].eb(v,i);
		g[v].eb(u,i);
	}
	rep(i,0,n-1){
		for(auto&[j,e1]:g[i])if(i<j){
			for(auto&[k,e2]:g[j])if(i<k&&j<k){
				for(auto&[t,e3]:g[k])if(t==i){
					ps2(e1,e2,e3);
				}
			}
		}
	}
	vector<int>pd(m+1);
	vector<vector<int> >b(m+1);
	auto push=[&](vector<int>x){
		rep(i,0,m)if(x[i]){
			if(i==m){
				puts("-1"),exit(0);
			}
			if(!pd[i]){
				pd[i]=1;
				b[i]=x;
				if(x[i]==2){
					for(auto&it:b[i]){
						it=it*2%3;
					}
				}
				return;
			}
			int k=x[i];
			rep(j,i,m){
				x[j]=(x[j]-b[i][j]*k+6)%3;
			}
			// assert(x[i]==0);
		}
	};
	for(auto&x:f){
		push(x);
	}
	per(i,m-1,0){
		if(pd[i]){
			int cur=b[i][m];
			rep(j,i+1,m-1){
				cur=(cur-b[i][j]*c[j]+6)%3;
			}
			c[i]=cur;
		}
	}
	rep(i,0,m-1){
		printf("%d ",(c[i]+3-1)%3+1);
	}
	puts("");
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&T);
	while(T--){
		sol();
	}
	return 0;
}