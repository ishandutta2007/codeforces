#include <bits/stdc++.h>
using namespace std;

int a[5], i;
vector<int> v;

int main(){
	for(i=0;i<5;i++)
		scanf("%d",&a[i]);
	while(a[3]>0){
		if(a[3]<=a[1]) {v.push_back(0);break;}
		else if(a[0]<=a[4]){v.push_back(1); a[0]+=a[2]-a[4];}
		else{v.push_back(0); a[3]-=a[1]; a[0]-=a[4];}
	}
	printf("%d\n",v.size());
	for(auto n : v)
		printf("%s\n",(n)?"HEAL":"STRIKE");
	return 0;
}