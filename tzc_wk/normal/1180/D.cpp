#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	cin>>n>>m;
	int up=1,down=n;
	while(up<down){
		for(int i=1;i<=m;i++){
			printf("%d %d\n%d %d\n",up,i,down,m-i+1);
		}
		up++;down--;
	}
	if(up==down){
		int lim=((m%2)?m/2+1:m/2);
		for(int i=1;i<=lim;i++){
			if(i!=m-i+1)
				printf("%d %d\n%d %d\n",up,i,down,m-i+1);
			else
				printf("%d %d\n",up,i);
		}
	}
}