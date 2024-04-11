#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
int main(){
	int t=in();
	while(t--){
		long long x;scanf("%lld",&x);
		int v=x%14;
		if(x>14&&v>=1&&v<=6)puts("YES");
		else puts("NO");	
	}
	return 0;
}