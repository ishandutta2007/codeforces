#include<stdio.h>
int IT[3000000], b;
int getsum(int f, int r){
	f+=b; r+=b;
	int re = 0;
	while(f<r){
		if(f%2 == 1) re += IT[f++];
		if(r%2 == 0) re += IT[r--];
		f/=2; r/=2;
	}
	if(f==r) re+=IT[f];
	return re;
}
void add(int x){
	IT[x+=b]++;
	while(x/=2)IT[x]++;
}
int main(){
	int n, k;
	long long f=1;
	scanf("%d%d", &n, &k);
	if(k*2 > n) k=n-k;
	for(b=1; b<=n; b*=2);
	int x=0;
	do{
		int s = x-k+1, e=x+k-1, r=0;
		if(s<0) r=getsum(s+n, n-1) + getsum(0, e);
		else if(e >= n) r = getsum(s, n-1) + getsum(0, e-n);
		else r = getsum(s, e);
		f+=r+1;
		printf("%lld ", f);
		add(x);
		(x+=k)%=n;
	} while(x);
	return 0;
}