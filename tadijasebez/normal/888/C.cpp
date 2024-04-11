#include <stdio.h>
#include <cstring>
const int N=100050;
const int M=30*2*N;
int x[M],ls[M],rs[M],clock,root[26];
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock;
	x[c]++;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
char ch[N];
int sol;
int min(int a, int b){ return a>b?b:a;}
int dp[N][26];
int main()
{
	int n,i,j,k,top,bot,mid,ans;
	scanf("%s",&ch);
	n=strlen(ch);
	for(i=0;i<n;i++) ch[i]-='a';
	sol=n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<26;j++) dp[i+1][j]=dp[i][j];
		dp[i+1][ch[i]]++;
		//Set(root[ch[i]],0,N-1,i);
	}
	//printf("%i\n",Get(root[0],0,N-1,1,n-1));
	for(j=0;j<26;j++)
	{
		top=n,bot=1,ans=n;
		while(top>=bot)
		{
			mid=top+bot>>1;
			bool ok=true;
			for(i=0;i<n-mid+1;i++)
			{
				//if(Get(root[j],0,N-1,i,i+mid-1)==0){ ok=false;break;}
				if(dp[i+mid][j]-dp[i][j]==0){ ok=false; break;}
			}
			//printf("%i %i\n",mid,ok);
			if(ok) top=mid-1,ans=mid;
			else bot=mid+1;
		}
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}