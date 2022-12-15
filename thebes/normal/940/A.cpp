#include <bits/stdc++.h>
using namespace std;

int n, d, i, j, x, cnt;
vector<int> vec;

int main(){
	for(scanf("%d%d",&n,&d),i=1;i<=n;i++)
		scanf("%d",&x),vec.push_back(x);
	sort(vec.begin(),vec.end());
	for(i=0;i<vec.size();i++){
		for(j=i;j<vec.size()&&vec[j]-vec[i]<=d;j++)
			cnt = max(cnt, j-i+1);
	}
	printf("%d\n",vec.size()-cnt);
	return 0;
}