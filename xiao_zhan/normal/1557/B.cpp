#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],b[200500];
map<int,int> mp;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		mp.clear();
		for(i=1;i<=n;i++){
			mp[b[i]]=i;
		}
		for(i=1;i<=n;i++){
			
			a[i]=mp[a[i]];
			
			//printf("%d ",a[i]);
		}
		//puts("");
		for(i=2;i<=n;i++){
			if(a[i]!=a[i-1]+1){
				m--;
			}
		}
		puts((m>0)?"yes":"no");
	}
}