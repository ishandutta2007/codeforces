#include<bits/stdc++.h>
using namespace std;
int T,n,a[3010];
vector<int>v;
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)if((i&1)!=(a[i]&1)){puts("-1");return;}
	for(int i=n;i>1;i-=2){
		for(int j=i;j>1;j-=2)if(a[j]==i){v.push_back(j),reverse(a+1,a+j+1);break;}
		for(int j=i-1;j>1;j-=2)if(a[j]==i-1){
			v.push_back(j-1),reverse(a+1,a+j);
			v.push_back(j+1),reverse(a+1,a+j+2);
			v.push_back(3),reverse(a+1,a+4);
			v.push_back(i),reverse(a+1,a+i+1);
			break;
		}
	}
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
	printf("%d\n",v.size());
	for(auto i:v)printf("%d ",i);puts("");
	v.clear();
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}