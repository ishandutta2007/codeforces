#include <bits/stdc++.h>
using namespace std;

int n, i, x, ans;
vector<int> vec;

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		if(x) vec.push_back(i);
	}
	if(vec.empty()) printf("0\n");
	else{
		ans++;
		for(i=1;i<vec.size();i++)
			ans += min(2,vec[i]-vec[i-1]);
		printf("%d\n",ans);
	}
	return 0;
}