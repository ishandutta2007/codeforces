#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
char s[10][10];
void solve(){
	for(int i=1;i<=8;i++){
		scanf("%s",s[i]+1);
	}
	bool flag=0;
	for(int i=1;i<=8;i++){
		flag=1;
		for(int j=1;j<=8;j++){
			if(s[i][j]!='R')flag=0;
		}
		if(flag){
			puts("R");
			return;
		}
	}
	puts("B");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}