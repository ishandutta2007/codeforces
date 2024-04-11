#include<cstdio>
#include<vector>
#define W 30

int q;

int main(){
	scanf("%d",&q);
	while(q--){
		int u,v;
		scanf("%d%d",&u,&v);
		std::vector<int> x,y;
		x.clear();
		y.clear();
		for(int i=W-1;i>=0;i--){
			if(u&(1<<i))
				x.push_back(i);
			if(v&(1<<i))
				y.push_back(i);
		}
		if(v<u||y.size()>x.size())
			puts("NO");
		else{
			bool flg=1;
			for(int i=1;i<=y.size();i++)
				if(x[x.size()-i]>y[y.size()-i])
					flg=0;
			puts(flg?"YES":"NO");
		}
	}
}