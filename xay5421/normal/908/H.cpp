#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
class dsu{
public:
	int n;
	vector<int>fa;
	vector<int>sz;
	dsu(){}
	dsu(int n_):n(n_),fa(n_),sz(n_,1){
		iota(fa.begin(),fa.end(),0);
	}
	void assign(int n_){
		*this=dsu(n_);
	}
	int find(int u){
		return fa[u]==u?u:fa[u]=find(fa[u]);
	}
	bool check(int u,int v){
		return find(u)==find(v);
	}
	bool unite(int u,int v){
		int u_=find(u);
		int v_=find(v);
		if(u_!=v_){
			if(sz[v_]<sz[u_]){
				int tmp=u_;
				u_=v_;
				v_=tmp;
			}
			sz[v_]+=sz[u_];
			fa[u_]=v_;
			return 1;
		}
		return 0;
	}
};
int n;
int main(){
	scanf("%d",&n);
	dsu o(n);
	vector<string>s(n);
	rep(i,0,n-1){
		cin>>s[i];
		rep(j,0,n-1){
			char c=s[i][j];
			if(c=='A'){
				o.unite(i,j);
			}else if(c=='C'){
				
			}else if(c=='X'){
				
			}
		}
	}
	rep(i,0,n-1)rep(j,0,n-1)if(i!=j&&o.check(i,j)&&s[i][j]!='A')puts("-1"),exit(0);
	vector<vector<int> >nodes(n);
	rep(i,0,n-1){
		nodes[o.find(i)].pb(i);
	}
	vector<int>id(n);
	vector<int>ele;
	rep(i,0,n-1){
		if(SZ(nodes[i])>=2){
			id[i]=SZ(ele);
			ele.pb(i);
		}
	}
	if(ele.empty()){
		printf("%d\n",n-1),exit(0);
	}
	vector<vector<char> >limits(SZ(ele),vector<char>(SZ(ele)));
	rep(i,0,SZ(ele)-1)rep(j,0,SZ(ele)-1){
		if(i==j){limits[i][j]='-';continue;}
		limits[i][j]='O';
		each(x,nodes[ele[i]])each(y,nodes[ele[j]])if(s[x][y]=='X'){
			limits[i][j]='X';
		}
	}
	vector<int>dp(1<<SZ(ele));
	dp[0]=1;
	rep(i,1,(1<<SZ(ele))-1)if(dp[i&(i-1)]){
		int low=__builtin_ctz(i);
		bool err=0;
		rep(j,0,SZ(ele)-1)if((i>>j&1)&&(j!=low)){
			if(limits[j][low]=='X')err=1;
		}
		if(!err)dp[i]=1;
	}
	for(int i=1;i<(1<<SZ(ele));i<<=1)for(int j=0;j<(1<<SZ(ele));j+=i<<1)for(int k=0;k<i;++k){
		dp[i+j+k]+=dp[j+k];
	}
	vector<int>coef(1<<SZ(ele));
	coef[(1<<SZ(ele))-1]=1;
	for(int i=1;i<(1<<SZ(ele));i<<=1)for(int j=0;j<(1<<SZ(ele));j+=i<<1)for(int k=0;k<i;++k){
		coef[j+k]-=coef[i+j+k];
	}
	vector<int>f(1<<SZ(ele),1);
	int ans=n-1;
	while(1){
		++ans;
		rep(i,0,(1<<SZ(ele))-1){
			f[i]*=dp[i];
		}
		int cur=0;
		rep(i,0,(1<<SZ(ele))-1){
			cur+=coef[i]*f[i];
		}
		if(cur){
			printf("%d\n",ans);
			exit(0);
		}
	}
	return 0;
}