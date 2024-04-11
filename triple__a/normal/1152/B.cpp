#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=20;
bool bits[maxn];
int steps[maxn];
int ans=0;
int t=0;
int tzd(){
	for (int i=t-1;i>=0;--i){
		if (!bits[i]){
			return i;
		}
	}
	return -1;
}
int main(){
	int n;
	scanf("%d",&n); 
	while(n){
		bits[t++]=n&1;
		n>>=1;
	}
	while(1){
		int u=tzd();
		if (u==-1){
			break;
		}
		ans++;
		steps[(ans+1)/2]=u+1;
		for (int i=0;i<=u;++i){
			bits[i]=1-bits[i]; 
		}
		u=tzd();
		if (u==-1){
			break;
		}
		ans++;
		int x=0;
		while(1){
			bits[x]=1-bits[x];
			if (bits[x]){
				break;
			}
			x++;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=(ans+1)/2;++i){
		printf("%d ",steps[i]);
	}
	return 0;
}