#include<cstdio>
#include<vector>

int T;

int n;

int x;

std::vector<int> ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans.clear();
		for(int i=2;i<=n;i++){
			printf("? %d 1\n",i-1);
			for(int j=1;j<=i-1;j++)
				printf("%d ",j);
			printf("\n%d\n",i);
			fflush(stdout);
			scanf("%d",&x);
			if(x!=0){
				for(int j=i+1;j<=n;j++){
					printf("? 1 1\n%d\n%d\n",i,j);
					fflush(stdout);
					scanf("%d",&x);
					if(!x)
						ans.push_back(j);
				}
				int L=1,R=i-1,res;
				while(L<=R){
					int mid=(L+R)>>1;
					printf("? %d 1\n",mid);
					for(int j=1;j<=mid;j++)
						printf("%d ",j);
					printf("\n%d\n",i);
					fflush(stdout);
					scanf("%d",&x);
					if(x){
						res=mid;
						R=mid-1;
					}
					else
						L=mid+1;
				}
				for(int j=1;j<=i-1;j++)
					if(j!=res)
						ans.push_back(j);
				printf("! %d ",ans.size());
				for(auto i:ans)
					printf("%d ",i);
				puts("");
				fflush(stdout);
				break;
			}
		}
	}
}