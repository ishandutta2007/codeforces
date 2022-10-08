#include"bits/stdc++.h"
typedef long long ll;
using namespace std;
int n,cnt1,cnt2;
int main(){
	scanf("%d",&n);int i,a,b;
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a>b)cnt1++;
		if(a<b)cnt2++;
	}
	puts(cnt1==cnt2?"Friendship is magic!^^":cnt1<cnt2?"Chris":"Mishka");
	return 0;
}