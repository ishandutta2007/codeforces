#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,A[110000],len;
void print(int k){
	putchar('A'+k%26);
	k/=26;
	while (k){
		putchar('a'+k%26); k/=26;
	}
	putchar(' ');
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<m;i++) A[i]=i;
	len=m-1;
	for (int i=m;i<=n;i++){
		char ch[10]; scanf("%s",ch+1);
		if (ch[1]=='N') A[i]=A[i-m+1]; else A[i]=++len;
	}
	//printf("Yes\n");
	for (int i=1;i<=n;i++) print(A[i]);
	return 0;
}