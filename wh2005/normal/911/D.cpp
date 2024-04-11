#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int n,m,a[2009],pos[2009];
int main(){
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		for(int j=1;j<i;j++){
			if(a[j]>a[i]) pos[i]++; 
		}
		ans+=pos[i];
	}
	scanf("%d",&m);
	int op;
	if(ans%2==0) op=0;
	else op=1;
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		if(((r-l+1)*(r-l)/2)%2==1) op=!op;
		if(op==1) printf("odd\n");
		else printf("even\n");
	}
	return 0;
}