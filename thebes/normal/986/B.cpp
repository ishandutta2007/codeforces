#include <bits/stdc++.h>
using namespace std;

int pos[1000006], arr[1000006], N, cnt, i, x;
int main(){
	for(scanf("%d",&N),i=1;i<=N;i++){
		scanf("%d",&x);
		pos[x]=i;arr[i]=x;
	}
	for(i=1;i<=N;i++){
		if(pos[i]==i) continue;
		cnt++; swap(arr[i],arr[pos[i]]);
		swap(pos[i],pos[arr[pos[i]]]);
	}
	if(N%2&&cnt%2) printf("Petr\n");
	else if(N%2==0&&cnt%2==0) printf("Petr\n");
	else printf("Um_nik\n");
	return 0;
}