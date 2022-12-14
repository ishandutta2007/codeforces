//*

#include<stdio.h>
#include<vector>

using namespace std;

bool isprime(int n) {
	for(int i=2;i*i<=n;i++) {
		if(n%i==0)return false;
	}
	return true;
}

int main() {
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int n;
	vector<int> ans;
	scanf("%d",&n);
	for(int i=2;i<=n;i++) {
		if(!isprime(i))continue;
		int v=i;
		while(v<=n) {
			ans.push_back(v);
			v*=i;
		}
	}
	printf("%d\n",ans.size());
	for(auto a:ans)printf("%d ",a);

	return 0;
}

//*/