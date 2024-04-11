#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1000005;
int n,m,T,ans;
int a[maxn],ok[maxn];
string s;
int gcd(int a,int b){
	return b==0? a:gcd(b,a%b);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),ok[x]=1;
	for(int i=1000000;i>=1;i--){
		int lst=0,tot=0;
		for(int j=i+i;j<=1000000;j+=i)
			if(ok[j])
				lst=gcd(lst,j),tot++;
		if(ok[i]==0&&tot>1&&lst==i)
			ans++,ok[i]=1;
	}
	printf("%d\n",ans);
	return 0;
}