#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg,top;
int a[maxn],stk[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		int lst=1,tot=0,rec=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=2;i<=n;i++){
			int j=i;
			while(j+1<=n&&a[j+1]>a[j])
				j++;
			if(tot==0)
				ans++;
			tot++;
			if(tot==lst)
				tot=0,lst=j-rec,rec=j;
			i=j;
		}
		printf("%d\n",ans);
	}
	return 0;
}