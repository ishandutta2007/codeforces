#include<bits/stdc++.h>
using namespace std;
long long a[1<<21];
long long b[1<<21];
int pop[1<<21]={};
char s[(1<<21)+10];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) a[i]=(s[i]-'0');
	scanf("%s",s);
	for(int i=0;i<(1<<n);i++) b[i]=(s[i]-'0');
	for(int i=1;i<(1<<n);i++) pop[i]=pop[i^(i&(-i))]+1;
	for(int i=0;i<(1<<n);i++) a[i]<<=2*pop[i];
	for(int i=0;i<(1<<n);i++) b[i]<<=2*pop[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			if((j>>i)&1) a[j]+=a[j^(1<<i)];
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			if((j>>i)&1) b[j]+=b[j^(1<<i)];
	for(int i=0;i<(1<<n);i++) a[i]*=b[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			if((j>>i)&1) a[j]-=a[j^(1<<i)];
	for(int i=0;i<(1<<n);i++) printf("%lld",(a[i]>>(2*pop[i]))&3ll);
	return 0;
}