#include <bits/stdc++.h>
using namespace std;

string s[12];
int x, y, i, j, all, f;

int main(){
	for(i=0;i<9;i++){
		getline(cin,s[i]);
		if(i==2||i==5) getline(cin,s[i+1]);
	}
	scanf("%d%d",&x,&y); x--; y--;
	swap(x,y); x%=3; y%=3;
	for(i=y*3;i<y*3+3;i++){
		for(j=4*x;j<4*x+3;j++){
			if(s[i][j]=='.') f=1;
		}
	}
	if(f){
		for(i=y*3;i<y*3+3;i++){
			for(j=4*x;j<4*x+3;j++){
				if(s[i][j]=='.') s[i][j]='!';
			}
		}
		for(i=0;i<9;i++){
			cout << s[i];
			if(i==2||i==5) cout<<'\n';
			printf("\n");
		}
	}
	else{
		for(i=0;i<9;i++){
			for(j=0;j<s[i].size();j++){
				if(s[i][j]=='.') printf("%c",'!');
				else printf("%c",s[i][j]);
			}
			cout<<'\n';
			if(i==2||i==5) cout<<'\n';
		}
	}
	return 0;
}