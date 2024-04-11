#include <bits/stdc++.h>
using namespace std;
char s[1000005];
int n,k,z[1000005],delta[1000005];
inline void Z_algorithm(){
	int l=0,r=0;
	for(int i=1;i<n;i++){
		if(i<=r)	z[i]=min(z[i-l],r-i);
		while(i+z[i]<n&&s[i+z[i]]==s[z[i]])	z[i]++;
		if(i+z[i]>r){
			l=i;
			r=i+z[i];
		}
	}
}
int main(){
	scanf("%d%d%s",&n,&k,s);
	Z_algorithm();
	for(int len=1;len*k<=n;len++){
		int x=z[len];
		if(x>=len*(k-1)){
			delta[len*k]++;
			delta[min(len*k+len,len+x)+1]--;
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=delta[i];
		if(sum>0)	putchar('1');
		else		putchar('0');
	}
}