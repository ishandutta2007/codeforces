#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <set>
#include <vector>
using namespace std;
#define N 200005
int n,k,sta[N],top,nxt[N],vis[N];char s[N],ans[N];
int main()
{
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1,len=0;i<=n;i++)
	{
		if(s[i]=='(')sta[++top]=i;
		else len+=2,vis[i]=vis[sta[top--]]=1;
		if(len==k)break;
	}
	for(int i=1;i<=n;i++)if(vis[i])printf("%c",s[i]);
}