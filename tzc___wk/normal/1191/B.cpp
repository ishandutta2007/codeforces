#include <bits/stdc++.h>
using namespace std;
string s[4];
int main(){
	cin>>s[1]>>s[2]>>s[3];
	if(s[1]==s[2]&&s[2]==s[3])	return puts("0"),0;
	sort(s+1,s+4);
	if(s[1][0]==s[2][0]-1&&s[2][0]==s[3][0]-1&&s[1][1]==s[2][1]&&s[3][1]==s[2][1])
		return puts("0"),0;
	if(s[1]==s[2]||s[2]==s[3]||s[3]==s[1])
		return puts("1"),0;
	for(int i=1;i<=3;i++){
		for(int j=i+1;j<=3;j++){
			if(s[i][1]==s[j][1]){
				if(abs(s[i][0]-s[j][0])==1||abs(s[i][0]-s[j][0])==2)
					return puts("1"),0;
			}
		}
	}
	puts("2");
	return 0;
}