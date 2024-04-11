#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

int n,m;
char a[2000],b[2000];
int main() {
	scanf("%d %d",&n,&m);
	scanf("%s",a);
	scanf("%s",b);
	
	int min=std::max(m,n)+1;
	std::vector<int> res;
	for(int i=0;i<=m-n;i++) {
		int cnt=0;
		std::vector<int> ch;
		for(int j=0;j<n;j++) {
			if(a[j]!=b[i+j]) ch.push_back(j+1),cnt++;
		}
		if(min>cnt) {
			min=cnt;
			std::swap(res,ch);
		}
	}
	printf("%d\n",min);
	for(auto &it:res) printf("%d ",it);
	
	return 0;
}