#include<cstdio>
#define ll long long

ll n;

int main(){
	scanf("%I64d",&n);
	ll tmp=0,cnt=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		a=a>0?0:1;
		tmp^=a;
		if(tmp)
			cnt++;
	}
	printf("%I64d %I64d",cnt*(n+1-cnt),n*(n+1)/2-cnt*(n+1-cnt));
}