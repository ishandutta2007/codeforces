#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define PB push_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
int n,m;
int ans=1e9;
#ifdef xay5421
int mp[1005][1005];
int qry(int x,int y){
	assert(x>0&&x<=n);
	assert(y>0&&y<=m);
	D("qry %d %d\n",x,y);
	ans=min(ans,mp[x][y]);
	return mp[x][y];
}
#else
int qry(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	int z;
	scanf("%d",&z);
	ans=min(ans,z);
	return z;
}
#endif
vector<int>sol(vector<int>r,vector<int>c){
	if(SZ(r)<=2){
		vector<int>res(SZ(r),1e9);
		rep(i,0,SZ(r)-1){
			int mn=1e9;
			rep(j,0,SZ(c)-1){
				int num=qry(r[i],c[j]);
				if(num<mn){
					mn=num;
					res[i]=c[j];
				}
			}
		}
		return res;
	}
	if(SZ(r)<SZ(c)){
		vector<int>nc;
		rep(i,0,SZ(c)-1){
			while(SZ(nc)&&qry(r[SZ(nc)-1],c[i])<qry(r[SZ(nc)-1],nc.back())){
				nc.pop_back();
			}
			if(SZ(nc)<SZ(r)){
				nc.PB(c[i]);
			}
		}
		return sol(r,nc);
	}else{
		vector<int>nr;
		for(int i=0;i<SZ(r);i+=2){
			nr.PB(r[i]);
		}
		vector<int>ores(sol(nr,c));
		vector<int>res(SZ(r));
		rep(i,0,SZ(ores)-1){
			res[i*2]=ores[i];
		}
		for(int i=1;i<SZ(r);i+=2){
			int lb=lower_bound(c.begin(),c.end(),ores[i/2])-c.begin();
			int rb=i+1>=SZ(r)?SZ(c)-1:lower_bound(c.begin(),c.end(),ores[i/2+1])-c.begin();
			int mn=1e9;
			rep(j,lb,rb){
				int num=qry(r[i],c[j]);
				if(num<mn){
					mn=num;
					res[i]=c[j];
				}
			}
		}
		return res;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
#ifdef xay5421
	rep(i,1,n)rep(j,1,m)scanf("%d",&mp[i][j]);
#endif
	vector<int>r,c;
	rep(i,1,n)r.PB(i);
	rep(i,1,m)c.PB(i);
	vector<int>res(sol(r,c));
	printf("! %d\n",ans);
#ifdef xay5421
	rep(i,1,n)rep(j,1,m){
		assert(res[i-1]);
		assert(make_pair(mp[i][res[i-1]],res[i-1])<=make_pair(mp[i][j],j));
	}
#endif
	return 0;
}