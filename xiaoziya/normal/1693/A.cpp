#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int a[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		long long sum=0;
		int flg=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(i>1&&sum==0&&a[i]>0)
				flg=1;
			sum+=a[i];
			if(sum<0)
				flg=1;
		}
		flg|=(sum!=0);
		puts(flg==0? "Yes":"No");
	}
	return 0;
}