#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int T,n,k,flg;
int x[maxn],y[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k),flg=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;i++){
			int tot=0;
			for(int j=1;j<=n;j++)
				tot+=(abs(x[i]-x[j])+abs(y[i]-y[j])<=k);
			if(tot==n){
				puts("1"),flg=1;
				break;
			}
		}
		if(flg==0)
			puts("-1");
	}
	return 0;
}