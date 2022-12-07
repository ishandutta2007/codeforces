#include<bits/stdc++.h>

using namespace std;

const int N=100005;
const int mo=1000000007;
int f[N];
int main(){
	f[1]=1;
	for (int i=2;i<N;i++)
		f[i]=1ll*f[i-1]*(2*i-1)%mo*(2*i)%mo;
	int T;
	scanf("%d",&T);
	while (T--){
		int x;
		scanf("%d",&x);
		printf("%d\n",f[x]);
	}
}