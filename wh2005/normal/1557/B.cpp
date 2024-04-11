#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+9;
int T,n,k,a[N];
struct pp{int val,id;}b[N];
bool cmp(pp x,pp y){return x.val<y.val;}



int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);	
		for(int i=1;i<=n;i++){
			b[i].val=a[i],b[i].id=i;
		}
		sort(b+1,b+n+1,cmp);
		for(int i=1;i<=n;i++) a[b[i].id]=i;
		int m=1;
		for(int i=2;i<=n;i++){
			if(b[i].id!=b[i-1].id+1) m++;
		}	
		if(m<=k) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}