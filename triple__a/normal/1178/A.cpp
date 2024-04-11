#include<bits/stdc++.h>
using namespace std;
const int maxn=10000007;
int a[maxn],sum=0,ps=0,n;
vector<int> vec;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	sum=ps=a[1];
	vec.push_back(1); 
	for (int i=2;i<=n;++i){
		if (2*a[i]<=a[1]) ps+=a[i],vec.push_back(i);
		sum+=a[i];
	}
	if (2*ps>sum){
		printf("%d\n",vec.size());
		for (auto c:vec){
			printf("%d ",c);
		}
	}
	else{
		printf("0");
	}
	return 0;
}