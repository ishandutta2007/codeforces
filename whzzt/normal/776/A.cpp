#include"bits/stdc++.h"
using namespace std;

const int N = 1005;
char s1[20],s2[20],s3[20],s4[20];
int n;

bool equal (char*x,char*y){
	int lx=strlen(x),ly=strlen(y);
	if(lx!=ly)return false;
	for(int i=0;i<lx;i++)if(x[i]!=y[i])return false;
	return true;
}

int main(){
	scanf("%s%s",s1,s2);
	scanf("%d",&n);
	printf("%s %s\n",s1,s2);
	for (int i=1; i<=n; i++){
		scanf("%s%s",s3,s4);
		if (equal(s1,s3)) memcpy(s1,s4,sizeof(s4));
		else memcpy (s2,s4,sizeof(s4));
		printf("%s %s\n",s1,s2);
	}
	return 0;
}