#include<bits/stdc++.h>
using namespace std;
int n,ans,x,y,last;
char s[1000000];
int main()
{
	scanf("%d",&n);
	scanf("%s",&s);
	if (s[0]=='U')
	 {
	 	x=0;y=1;
	 	last=0;
	 }
	else
	 {
	 	x=1;y=0;
	 	last=1;
	 } 
	for (int i=1;i<n;i++)
	 {
		if (s[i]=='U')y++;
		else x++;
		if (last==0&&x>y)
		 {
		 	last=1;
		 	ans++;
		 } 
		else if (last==1&&x<y)
		 {
		 	last=0;
		 	ans++;
		 } 
	 } 
	 printf("%d",ans);
}