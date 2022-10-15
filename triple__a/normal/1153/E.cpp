#include<bits/stdc++.h>
using namespace std;

int n;

bool query(int x1,int y1,int x2,int y2){
	printf("? %d %d %d %d\n",x1,y1,x2,y2);
	fflush(stdout);
	int u;
	scanf("%d",&u);
	return u%2;
}

int main(){
	scanf("%d",&n);
	bool fg=false;
	int rec[7],ans[7],cnt=0;
	for (int i=1;i<=n;++i){
		if (query(i,1,i,n)){
			fg=true;
			rec[++cnt]=i;
		}
	}
	if (fg){
		for (int j=1;j<=2;++j){
			int l=1,r=n,md=(l+r)>>1;
			while(l<r){
				md=(l+r)>>1;
				if (query(rec[j],l,rec[j],md)){
					r=md;
				}
				else{
					l=md+1;
				}
			}
			ans[j]=l;
		} 
		printf("! %d %d %d %d\n",rec[1],ans[1],rec[2],ans[2]);
		return 0;
	}
	for (int i=1;i<=n;++i){
		if (query(1,i,n,i)){
			rec[++cnt]=i;
		}
	}
	int l=1,r=n,md=(l+r)>>1;
	while (l<r){
		md=(l+r)>>1;
		if (query(l,rec[1],md,rec[1])){
			r=md;
		}
		else{
			l=md+1;
		}
	}
	printf("! %d %d %d %d\n",l,rec[1],l,rec[2]);
	return 0;
}