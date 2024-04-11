//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#include<string.h>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

char str[100],cc[100]="CODEFORCES";

char *pos(char *s,char c){
	for(int i=0;;i++){
		if(s[i]==0)return s+i;
		if(s[i]==c)return s+i;
	}
	return s;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	char* A=str;
	int L;
	scanf("%s",str);
	L=strlen(str);
	if(L<10){
		puts("NO");
		return 0;
	}
	for(int t=0;t<=10;t++){
		int i;
		for(i=0;i<t;i++){
			if(cc[i]!=str[i])break;
		}
		if(i<t)continue;
		for(i=L-(10-t);i<L;i++){
			if(cc[i-L+10]!=str[i])break;
		}
		if(i<L)continue;
		puts("YES");
		return 0;
	}
	puts("NO");
	return 0;
}
//*/