#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	vector<int> v;
	for(int i=0;i<=30;i++)if(n&(1<<i))v.push_back(1<<i);
	if((int)v.size()>k){
		printf("NO");
		return 0;
	}
	k-=(int)v.size();
	for(int i=0;i<(int)v.size();i++){
		while(v[i]>1&&k>0){
			v[i]/=2;
			k--;
			v.push_back(v[i]);
		}
	}
	if(k){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	sort(v.begin(),v.end());
	for(int c:v)printf("%i ",c);
	return 0;
}