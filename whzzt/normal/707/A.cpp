#include"bits/stdc++.h"
using namespace std;
int n,m;char ch;bool flag;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		do{ch=getchar();}while(ch<'A'||ch>'Z');
		if(ch!='W'&&ch!='B'&&ch!='G')flag=true;
	}
	if(flag)puts("#Color");
	else puts("#Black&White");
	return 0;
}