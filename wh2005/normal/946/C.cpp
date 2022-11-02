#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
char s[100009];
int tot;
int main(){
	char ch=getchar();tot=0;
	int p=0,flag=0;
	while(ch>='a'&&ch<='z'){
		s[++tot]=ch;
		char t='a'+p;
		if(ch<=t&&t<='z') p++,s[tot]=t;
		if(t=='z') flag=1;
		ch=getchar();
	}
	if(!flag){
		printf("-1\n");
		return 0;
	}
	for(int i=1;i<=tot;i++) printf("%c",s[i]);
	printf("\n");
	return 0;
}