#include<bits/stdc++.h>
#define fr first
#define sc second
#define N 500005

int n,d;
std::vector<std::pair<int,int>> a,b,c;

inline void sol(std::vector<std::pair<int,int>> &A){
	std::vector<std::pair<int,int>> res;
	std::sort(A.begin(),A.end(),[&](std::pair<int,int> x,std::pair<int,int> y){
		return x.sc==y.sc?x.fr>y.fr:x.sc<y.sc;
	});
	int mx=-1;
	for(auto i:A){
		int x=i.fr,y=i.sc;
		if(x>mx)
			mx=x,res.emplace_back(x,y);
	}
	A=res;
}

int f[N];

int cnt,ans;

int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>=d){
			if(x<y)
				a.emplace_back(x,y);
			else{
				b.emplace_back(y,x);
				cnt++;
			}
		}
	}
	sol(a),sol(b);
	for(auto i:a){
		int x=i.fr,y=i.sc;
		auto it=std::lower_bound(b.begin(),b.end(),std::make_pair(x+1,0));
		if(it==b.end()||it->second>=y)
			c.emplace_back(x,y);
	}
	std::swap(a,c);
	int m=a.size();
	f[m]=0;
	for(int i=m-1;~i;i--){
		f[i]=f[std::lower_bound(a.begin(),a.end(),std::make_pair(a[i].second,0))-a.begin()]+1;
		ans=std::max(ans,f[i]);
	}
	printf("%d\n",ans+cnt);
}