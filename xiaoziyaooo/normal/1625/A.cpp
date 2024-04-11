#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=500005;
int n,m,T,ans,l;
int a[maxn],cnt[100][2];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&l);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=0;j<l;j++)
				cnt[j][(a[i]>>j)&1]++;
		}
		int res=0;
		for(int i=0;i<l;i++){
			if(cnt[i][0]<cnt[i][1])
				res|=(1<<i);
			cnt[i][0]=cnt[i][1]=0;
		}
		printf("%d\n",res);
	}
	return 0;
}