//	:(	:(	:(
#include <bits/stdc++.h>
using namespace std;
//	:(	:(	:(

int main(){
//	:(	:(	:(

	int n,x;scanf("%i %i",&n,&x);
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(x%i==0&&x/i<=n)cnt++;
	}
	printf("%i\n",cnt);
	return 0;
}
//	:(	:(	:(