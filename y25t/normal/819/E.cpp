#include<cstdio>
#include<vector>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second

int n;

inline int shf(int x,int y){
	return (x-1+y+n)%n+1;
}

std::vector<std::pair<pii,pii> > ans;

int main(){
	scanf("%d",&n);
	if(n&1){
		for(int i=2,j=3;j<=n;i+=2,j+=2)
			for(int o=0;o<2;o++)
				ans.push_back(mp(mp(i,j),mp(1,0)));
		for(int i=2,j=3;j<=n;i+=2,j+=2)
			for(int k=2,l=3;k<i;k+=2,l+=2)
				for(int o=0;o<2;o++)
					ans.push_back(mp(mp(i,k),mp(j,l)));
	}
	else{
		for(int i=1;i<=n;i++)
			ans.push_back(mp(mp(i,shf(i,1)),mp(shf(i,2),0)));
		for(int k=3;k<=n/2;k++)
			for(int i=1;i<=n;i+=2)
				ans.push_back(mp(mp(i,shf(i,k)),mp(shf(i,1),shf(i,1-k))));
	}
	printf("%d\n",ans.size());
	for(auto x:ans)
		if(x.sec.sec)
			printf("4 %d %d %d %d\n",x.fir.fir,x.fir.sec,x.sec.fir,x.sec.sec);
		else
			printf("3 %d %d %d\n",x.fir.fir,x.fir.sec,x.sec.fir);
}