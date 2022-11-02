#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int T,n,ans[1009];
struct pp{int L,R;}p[1009];
void solve(){
	int t=p[1].L+1;ans[1]=p[1].L;
	for(int i=2;i<=n;i++){
		if(t>p[i].R){ans[i]=0;continue;}
		if(p[i].L>=t) t=p[i].L+1,ans[i]=p[i].L;
		else ans[i]=t,t++;	
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d",&p[i].L,&p[i].R);
		solve();
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");		
	}
	return 0;
}