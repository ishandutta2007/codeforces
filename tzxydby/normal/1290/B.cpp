#include<bits/stdc++.h>
int a[200100][30],Q,l,r;
char S[200100];
int main()
{
	scanf("%s",S+1);
	for(int i=1;S[i];i++)
	{
		for(int j=0;j<26;j++)
			a[i][j]=a[i-1][j];
		a[i][S[i]-'a']++;
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&l,&r);
		int cnt=0;
		for(int i=0;i<26;i++)
			if(a[l-1][i]!=a[r][i])
				cnt++;
		if(cnt>2||S[l]!=S[r]||l==r)
			puts("Yes");
		else 
			puts("No");
	}
	return 0;
}