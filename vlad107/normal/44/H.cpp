#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>
#include <stack>
#include <set>
#include <map>

int n;
long long f[100][100];
char s[1000];

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(s);  
	n=strlen(s);
	memset(f,0,sizeof(f));
	for (int i=0;i<10;i++)
		f[0][i]=1;
	for (int i=1;i<n;i++)
		for (int j=0;j<10;j++){
			int x=(int)s[i]-48+j;
			if (x%2==0)
				f[i][x/2]+=f[i-1][j];
			else{
				f[i][x/2]+=f[i-1][j];
				f[i][x/2+1]+=f[i-1][j];
			}
		}
	long long res=0;	
	for (int i=0;i<10;i++)
		res+=f[n-1][i];
	int x=(int)s[0]-48;
	bool ok=true;
	for (int i=1;i<n;i++){
		int y=x+s[i]-48;
		if (y%2==0)x=y/2;else{
		if (y/2==(int)s[i]-48)x=y/2;else
			x=y/2+1;
		}
		if (x!=(int)s[i]-48){
			ok=false;
			break;
		}
	}
	printf("%I64d\n",res-ok);
}