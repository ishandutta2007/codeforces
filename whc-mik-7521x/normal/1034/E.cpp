#include<bits/stdc++.h>
using namespace std;
const int N=3e6+10;
long long a[N],b[N],n;
void fwt(long long f[],int sgn) {
	for(int len=1;len<n;len<<=1){
		for(int i=0;i<n;i+=len<<1){
			for(int j=0;j<len;j++){
				f[i+j+len]+=sgn*f[i+j];
			}
		}
	}
}
char s1[N],s2[N];
int main(){
	scanf("%lld%s%s",&n,s1,s2);
	n=1<<n;
	for(int i=0;i<n;i++)a[i]=(s1[i]-'0')*(1ll<<(__builtin_popcount(i)*2));
	for(int i=0;i<n;i++)b[i]=(s2[i]-'0')*(1ll<<(__builtin_popcount(i)*2));
	fwt(a,1);
	fwt(b,1);
	for(int i=0;i<n;i++)a[i]*=b[i];
	fwt(a,-1);
	for(int i=0;i<n;i++)putchar(((a[i]>>(__builtin_popcount(i)*2))&3)+'0');
	return  0;
}