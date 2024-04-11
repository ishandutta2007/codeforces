#include<bits/stdc++.h>
using namespace std;
char st[110],st1[110];
int main(){
	int n,k=0;
	scanf("%d",&n);
	scanf("%s",st);
	for(int i=0;i<n;i++){
		int ok=0;
		if(st[i]=='o'&&st[i+1]=='g'&&st[i+2]=='o'){
			ok=1;
			while(st[i]=='o'&&st[i+1]=='g'&&st[i+2]=='o')
				i+=2;
		}
		if(ok){
			st1[++k]='*';
			st1[++k]='*';
			st1[++k]='*';
		}
		else	st1[++k]=st[i];
	}
	printf("%s\n",st1+1);
	return 0;
}