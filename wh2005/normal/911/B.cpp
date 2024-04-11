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
int n,a,b;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	int l=1,r=min(a,b),ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int pos=a/mid+b/mid;
		if(pos>=n){
			l=mid+1,ans=mid;
		} 
		else r=mid-1; 
	}
	printf("%d\n",ans);
	return 0;
}