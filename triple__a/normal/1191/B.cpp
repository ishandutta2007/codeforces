#include<bits/stdc++.h>
using namespace std;
 
char s[6][6];
int check[15][3];
int main(){
	memset(check,0,sizeof(check));
	cin>>s[0]>>s[1]>>s[2];
	for (int i=0;i<3;++i){
		if (s[i][1]=='m'){
			check[s[i][0]-'0'][0]++;
		}
		if (s[i][1]=='p'){
			check[s[i][0]-'0'][1]++;
		} 
		if (s[i][1]=='s'){
			check[s[i][0]-'0'][2]++;
		}
	}
	int ans=0;
	for (int i=1;i<=9;++i){
		for (int j=0;j<3;++j){
			int tmp=1;
			if (check[i][j]){
				ans=max(ans,check[i][j]);
				if (check[i+1][j]){
					tmp++;
				}
				if (check[i+2][j]){
					tmp++;
				}
				ans=max(ans,tmp);
			} 
		}
	}
	printf("%d\n",3-ans);
	return 0;
}