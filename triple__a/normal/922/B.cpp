#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;


int main(){
	int n,ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		for (int j=i;j<=n;++j){
			int k=i^j;
			if (k<=n&&k>=j&&k<i+j){
				++ans;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}