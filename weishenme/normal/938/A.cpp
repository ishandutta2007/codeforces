#include<bits/stdc++.h>
using namespace std;
int f[1005],len;
char s[105];
int main()
{
	scanf("%d",&len); 
	scanf("%s",&s);
	f['a']=f['e']=f['i']=f['u']=f['o']=f['y']=1;
	while (1)
	 {
	 	int flag=0;
		for (int i=0;i+1<len;i++)
		 if (f[s[i]]&&f[s[i+1]])
		  {
		  	flag=1;
		  	for (int j=i+1;j+1<len;j++)
		  	 s[j]=s[j+1];
		  	len--;
			break; 
		  }
		if (!flag)break;  
	 }
	for (int i=0;i<len;i++)putchar(s[i]); 
}