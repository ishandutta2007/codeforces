#include <bits/stdc++.h>
using namespace std;
string s,t[5]; 
int main(){
	cin>>s;
	for(int i=0;i<5;i++){
		cin>>t[i];
		if(t[i][0]==s[0]||t[i][1]==s[1]){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}