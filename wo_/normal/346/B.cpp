#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string str1,str2,virus;

int dp[110][110][110];
int previ[110][110][110];
int prevj[110][110][110];
int prevk[110][110][110];

int fail[110];

void getFail()
{
	fail[0]=-1;
	int j=-1;
	for(int i=1;i<=virus.size();i++)
	{
		while(j>=0&&virus[i-1]!=virus[j]) j=fail[j];
		j++;
		fail[i]=j;
	}
}

int main()
{
	cin>>str1>>str2>>virus;
	int N=str1.size(),M=str2.size();
	int vln=virus.size();
	getFail();
//	for(int i=0;i<vln+1;i++) printf("%d ",fail[i]);
//	printf("\n");
	for(int i=0;i<110;i++) for(int j=0;j<110;j++) for(int k=0;k<110;k++)
	{
		dp[i][j][k]=-1;
	}
	dp[0][0][0]=0;
/*	for(int i=1;i<=N;i++) for(int j=1;j<=M;j++)
	{
		//k=0
		int &res=dp[i][j][0];
		int &pi=previ[i][j][0];
		int &pj=prevj[i][j][0];
		int &pk=prevk[i][j][0];
		res=dp[i-1][j][0];
		pi=i-1,pj=j,pk=0;
		if(res<dp[i][j-1][0])
		{
			res=dp[i][j-1][0];
			pi=i,pj=j-1;
		}
		if(str1[i-1]==str2[j-1])
		{
			for(int k=0;k<vln;k++)
			{
				if(virus[k]==str1[i-1]) continue;
				if(res<dp[i-1][j-1][k]+1)
				{
					res=dp[i-1][j-1][k]+1;
					pi=i-1,pj=j-1,pk=k;
				}
			}
		}
		//end k=0;
		
		for(int k=1;k<vln;k++)
		{
			int &res=dp[i][j][k];
			int &pi=previ[i][j][k];
			int &pj=prevj[i][j][k];
			int &pk=prevk[i][j][k];
			res=dp[i-1][j][k];
			pi=i-1,pj=j,pk=k;
			if(res<dp[i][j-1][k])
			{
				res=dp[i][j-1][k];
				pi=i,pj=j-1,pk=k;
			}
			if(str1[i-1]==str2[j-1]&&str1[i-1]==virus[k-1])
			{
				if(res<dp[i-1][j-1][k-1]+1)
				{
					res=dp[i-1][j-1][k-1]+1;
					pi=i-1,pj=j-1,pk=k-1;
				}
			}
		}
	}*/
	for(int i=0;i<=N;i++) for(int j=0;j<=M;j++)
	{
		for(int k=0;k<vln;k++)
		{
			if(i+1<=N&&dp[i+1][j][k]<dp[i][j][k])
			{
				dp[i+1][j][k]=dp[i][j][k];
				previ[i+1][j][k]=i;
				prevj[i+1][j][k]=j;
				prevk[i+1][j][k]=k;
			}
			if(j+1<=M&&dp[i][j+1][k]<dp[i][j][k])
			{
				dp[i][j+1][k]=dp[i][j][k];
				previ[i][j+1][k]=i;
				prevj[i][j+1][k]=j;
				prevk[i][j+1][k]=k;
			}
			if(i<N&&j<M&&str1[i]==str2[j])
			{
				int nk=k;
				while(nk>=0&&virus[nk]!=str1[i]) nk=fail[nk];
				nk++;
				if(dp[i+1][j+1][nk]<dp[i][j][k]+1)
				{
					dp[i+1][j+1][nk]=dp[i][j][k]+1;
					previ[i+1][j+1][nk]=i;
					prevj[i+1][j+1][nk]=j;
					prevk[i+1][j+1][nk]=k;
				}
			}
		}
	}
	int Ma=-1,kk=-1;
	for(int k=0;k<vln;k++)
	{
		if(Ma<dp[N][M][k])
		{
			Ma=dp[N][M][k];
			kk=k;
		}
	}
	if(Ma==0)
	{
		cout<<"0"<<"\n";
		return 0;
	}
	string ans;
	int ii=N,jj=M;
	while(!(ii==0&&jj==0))
	{
		int di=ii-previ[ii][jj][kk];
		int dj=jj-prevj[ii][jj][kk];
		if(di!=0&&dj!=0) ans+=str1[ii-1];
		kk=prevk[ii][jj][kk];
		ii-=di;
		jj-=dj;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<"\n";
	return 0;
}