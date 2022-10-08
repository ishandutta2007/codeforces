#include "bits/stdc++.h"
using namespace std;
int l,col[4],ans[5];
char s[105];
inline int gt(char x){
	if(x=='R')return 1;
	if(x=='B')return 2;
	if(x=='Y')return 3;
	return 4;
}
int main(){
	scanf("%s",s);l=strlen(s);
	for(int i=0;i<l;i++)if(s[i]!='!')col[i%4]=gt(s[i]);
	for(int i=0;i<l;i++)if(s[i]=='!')ans[col[i%4]]++;
	for(int i=1;i<=4;i++)printf("%d ",ans[i]);
	return 0;
}