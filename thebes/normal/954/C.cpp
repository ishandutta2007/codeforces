#include <bits/stdc++.h>
using namespace std;

const int MN = 2e5+5;
int N, i, x, p, b=-1, flag, arr[MN];

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&arr[i]);
	for(i=1;i<N;i++){
		if(arr[i]==arr[i+1]){flag=1; break;}
		if(abs(arr[i]-arr[i+1])!=1){
			if(b==-1) b=abs(arr[i]-arr[i+1]);
			else if(b!=abs(arr[i]-arr[i+1])) flag=1;
		}
	}
	if(flag) printf("NO\n");
	else{
		if(b==-1) b=1;
		int y = 0;
		for(i=1;i<N;i++){
			if(abs(arr[i]-arr[i+1])==1&&b!=1){
				if((arr[i]-1)/b!=(arr[i+1]-1)/b) flag=1;
			}
			else if(arr[i]>arr[i+1]) y--;
			else y++;
		}
		if(flag) printf("NO\n");
		else printf("YES\n1000000000 %d\n",b);
	}
	return 0;
}