#include <bits/stdc++.h>
using namespace std;

int a[2], b[2], A, B, C, D, i, lst;
pair<int,int> ans(0,0);
int main(){
	scanf("%d%d",&a[0],&a[1]);
	b[0] = a[0], b[1] = a[1];
	if(a[0]){
	a[0]--; lst = 0;
	for(i=1;a[0]+a[1];i++){
		if(i%2){
			if(a[!lst]) a[!lst]--, lst=!lst, B++;
			else a[lst]--, A++;
		}
		else{
			if(a[lst]) a[lst]--, A++;
			else a[!lst]--, lst=!lst, B++;
		}
	}
	if(A>=ans.first) ans={A,B};
	}
	if(b[1]){
	b[1]--; lst=1;
	for(i=1;b[0]+b[1];i++){
		if(i%2){
			if(b[!lst]) b[!lst]--, lst=!lst, D++;
			else b[lst]--, C++;
		}
		else{
			if(b[lst]) b[lst]--, C++;
			else b[!lst]--, lst=!lst, D++;
		}
	}
	if(C>=ans.first) ans={C,D};
	}
	printf("%d %d\n",ans.first,ans.second);
	getchar(); getchar();
}