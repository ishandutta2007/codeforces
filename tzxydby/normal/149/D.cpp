#include<bits/stdc++.h>
using namespace std;
const int N=705;
int f[N][N][3][3],l[N],st[N],ss,n,p=1000000007;
char s[N];
int dfs(int x,int y,int l,int r)
{
	if(x>y)
		return 1;
	int &t=f[x][y][l][r];
	if(t>=0)
		return t;
	t=0;
	int q=::l[x];
	for(int i=1;i<3;i++)
	{
		if(q<y||i!=r)
			t=(t+(long long)dfs(x+1,q-1,0,i)*dfs(q+1,y,i,r))%p;
		if(i!=l)
			t=(t+(long long)dfs(x+1,q-1,i,0)*dfs(q+1,y,0,r))%p;
	}
	return t;
}
int main()
{
	memset(f,-1,sizeof f);
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		if(s[i]=='(')
			st[ss++]=i;
		else
			l[st[--ss]]=i;
	} 
	printf("%d\n",dfs(0,n-1,0,0));
	return 0;
}