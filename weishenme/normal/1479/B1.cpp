#include<bits/stdc++.h>
using namespace std;
int n,x,A,B,ans;
int main(){
	scanf("%d",&n);
	while (n--){
		scanf("%d",&x);
		if (x==A){
			ans+=B!=x;
			B=x;
		}
		else if (x==B){
			ans+=A!=x;
			A=x;
		}
		else if (A==B){
			A=x;
			ans++;
		}
		else {
			A=x;
			B=0;
			ans++;
		}
	}
	printf("%d\n",ans);
}