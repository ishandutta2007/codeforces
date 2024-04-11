#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,q,a[N],pos[N],tp[N];
signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
	for(int x=2;x<=n;x++){
		pos[x]=pos[x-1];
		if(a[x-1]==a[x]){
			pos[x]++;
			tp[pos[x]]=(a[x]?1:-1);
		}
	}
	for (int x=1;x<N;x++) tp[x]+=tp[x-1];
	while(q--){
        int x,y;
		scanf("%d%d",&x,&y);
		x=pos[x];
		y=pos[y];
		printf("%d\n",1+(y-x+abs(tp[y]-tp[x]))/2);
	}
}