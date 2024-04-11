#include<cstdio>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define N 200005

int n,a[N];

bool vis[N];

std::vector<std::vector<int> > c;

std::vector<pii> ans;

inline void sol(std::vector<int> &x,std::vector<int> &y){
//	printf("&%d %d\n",x.size(),y.size());
	int u=x[0],v=y[0];
	ans.push_back(mp(u,v));
	for(auto i:x)
		if(i!=u)
			ans.push_back(mp(v,i));
	for(auto i:y)
		if(i!=v)
			ans.push_back(mp(u,i));
	ans.push_back(mp(u,v));
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			std::vector<int> tmp;
			tmp.clear();
			for(int j=i;!vis[j];j=a[j]){
				vis[j]=1;
				tmp.push_back(j);
			}
			if(tmp.size()>1)
				c.push_back(tmp);
		}
	if(c.size()==1&&c[0].size()==n){
		ans.push_back(mp(c[0][0],c[0][1]));
		ans.push_back(mp(c[0][1],c[0][2]));
		ans.push_back(mp(c[0][0],c[0][2]));
		for(int i=4;i<=n;i++)
			ans.push_back(mp(c[0][1],c[0][i-1]));
		ans.push_back(mp(c[0][0],c[0][1]));
	}
	else{
		while(c.size()>1){
			std::vector<int> x=c.back();
			c.pop_back();
			std::vector<int> y=c.back();
			c.pop_back();
			sol(x,y);
		}
		if(c.size()){
			std::vector<int> x=c.back(),y;
			y.clear();
			for(auto i:x)
				vis[i]=0;
			for(int i=1;i<=n;i++)
				if(vis[i]){
					y.push_back(i);
					break;
				}
			sol(x,y);
		}
	}
	printf("%d\n",ans.size());
	for(auto i:ans)
		printf("%d %d\n",i.first,i.second);
}