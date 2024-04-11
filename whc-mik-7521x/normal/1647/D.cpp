#include<bits/stdc++.h>
using namespace std;
int prime(int x){
	for(int i=2;i*i<=x;++i){
		if(x%i==0)
			return i;
	}
	return -1;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,d;
		scanf("%d%d",&x,&d);
		int cnt=0;
		while(x%d==0){
			++cnt;
			x/=d;
		}
		if(cnt==1)puts("NO");
		else if(prime(x)!=-1)puts("YES");
		else if(prime(d)!=-1&&d==prime(d)*prime(d)&&x==prime(d)&&cnt==3)puts("NO");
		else if(cnt>2&&prime(d)!=-1)puts("YES");
		else puts("NO");
	}
}