#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
char var[5010][20];
int v[2][5010];

struct formula
{
	int op;// 0:const(v1) 1:and 2:or 3:xor 
	int v1,v2;
	char cst[1010];
}F[5010];

string ansmax,ansmin;

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=N;i++)
	{
		char tmp[1010];
		scanf("%s := %s",var[i],F[i].cst);
		if (F[i].cst[0]=='0' || F[i].cst[0]=='1') continue;
		if (F[i].cst[0]=='?') F[i].v1 = N+1;
		else 
		{
			for (int j=1;j<i;j++)
			if (strcmp(F[i].cst,var[j])==0)
			{
				F[i].v1 = j;
				break;
			}
		}
		scanf("%s",tmp);
		if (tmp[0]=='A') F[i].op = 1;
		if (tmp[0]=='O') F[i].op = 2;
		if (tmp[0]=='X') F[i].op = 3;
		
		scanf("%s",tmp);
		if (tmp[0]=='?') F[i].v2 = N+1;
		else 
		{
			for (int j=1;j<i;j++)
			if (strcmp(tmp,var[j])==0)
			{
				F[i].v2 = j;
				break;
			}
		}
	}
	ansmax = "";
	ansmin = ""; 
	v[0][N+1] = 0;
	v[1][N+1] = 1;
	for (int i=0;i<M;i++)
	{
		int cnt[2];
		cnt[0] = cnt[1] = 0;
		for (int j=1;j<=N;j++)
		{
			for (int k=0;k<=1;k++)
			{
				if (F[j].op==0) v[k][j] = F[j].cst[i]-'0';
				if (F[j].op==1) v[k][j] = v[k][F[j].v1] & v[k][F[j].v2];
				if (F[j].op==2) v[k][j] = v[k][F[j].v1] | v[k][F[j].v2];
				if (F[j].op==3) v[k][j] = v[k][F[j].v1] ^ v[k][F[j].v2];
				if (v[k][j]) cnt[k]++;
			}
		}
		if (cnt[0]==cnt[1])
		{
			ansmax+="0";
			ansmin+="0";
		}
		else if (cnt[0]>cnt[1])
		{
			ansmax+="0";
			ansmin+="1";
		}
		else 
		{
			ansmax+="1";
			ansmin+="0";
		}
	}
	cout<<ansmin<<endl<<ansmax<<endl;
}