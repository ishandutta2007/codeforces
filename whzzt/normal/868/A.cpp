#include<bits/stdc++.h>

using namespace std;

char a[5],s[105][5];
int n;

int main(){
	scanf("%s",a+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		if(s[i][2]==a[1]&&s[j][1]==a[2])puts("YES"),exit(0);
	for(int i=1;i<=n;i++)if(s[i][1]==a[1]&&s[i][2]==a[2])puts("YES"),exit(0);
	puts("NO");
	return 0; 
}