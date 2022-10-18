#include<cstdio>
#include<algorithm>
#define N 1005

int T;

int n;
std::vector<int> a;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if(x==1)
				a.push_back(x);
			else{
				while(a.size()){
					if(x==a.back()+1){
						a.back()++;
						break;
					}
					a.pop_back();
				}
			}
			for(int j=0;j<a.size();j++){
				printf("%d",a[j]);
				if(j!=a.size()-1)
					putchar('.');
			}
			puts("");
		}
		a.clear();
	}
}