#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
vector<vector<char> > s;
int n,m;
char s1[N];
int solve(int x){
	int num[n][m],chafen[n][m];	
	memset(num,0,sizeof num);
	memset(chafen,0,sizeof chafen);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			num[i][j]=s[i][j]=='X';
	for (int i=0;i<n;i++)
		for (int j=1;j<m;j++)num[i][j]+=num[i][j-1];
	for (int i=1;i<n;i++)
		for (int j=0;j<m;j++)num[i][j]+=num[i-1][j];
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++)
			if (i-x>=0&&j-x>=0&&i+x<n&&j+x<m&&num[i+x][j+x]+(i-x&&j-x?num[i-x-1][j-x-1]:0)-
			(i-x?num[i-x-1][j+x]:0)-(j-x?num[i+x][j-x-1]:0)==(x*2+1)*(x*2+1))
				putchar('X');
			else putchar('.');
		puts("");	
	}
	for (int i=n-2;i>=0;i--)
		for (int j=0;j<m;j++)chafen[i][j]+=chafen[i+1][j];
	for (int i=0;i<n;i++)		
		for (int j=m-2;j>=0;j--)chafen[i][j]+=chafen[i][j+1];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='X'&&!chafen[i][j])return 0;
	return 1;			 
};	
int pd(int x){
	int num[n][m],chafen[n][m];	
	memset(num,0,sizeof num);
	memset(chafen,0,sizeof chafen);
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			num[i][j]=s[i][j]=='X';
	for (int i=0;i<n;i++)
		for (int j=1;j<m;j++)num[i][j]+=num[i][j-1];
	for (int i=1;i<n;i++)
		for (int j=0;j<m;j++)num[i][j]+=num[i-1][j];
	for (int i=x;i<n-x;i++)
		for (int j=x;j<m-x;j++){
			if (num[i+x][j+x]+(i-x&&j-x?num[i-x-1][j-x-1]:0)-
			(i-x?num[i-x-1][j+x]:0)-(j-x?num[i+x][j-x-1]:0)==(x*2+1)*(x*2+1)){
				chafen[i+x][j+x]++;
				if (i-x&&j-x)chafen[i-x-1][j-x-1]++;
				if (i-x)chafen[i-x-1][j+x]--;
				if (j-x)chafen[i+x][j-x-1]--;
			}
		}
	for (int i=n-2;i>=0;i--)
		for (int j=0;j<m;j++)chafen[i][j]+=chafen[i+1][j];
	for (int i=0;i<n;i++)		
		for (int j=m-2;j>=0;j--)chafen[i][j]+=chafen[i][j+1];
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			if (s[i][j]=='X'&&!chafen[i][j])return 0;
	return 1;			 
};	
signed main(){
	scanf("%d%d",&n,&m);
	s.resize(n);
	for (int i=0;i<n;i++){
		scanf("%s",s1);
		for (int j=0;j<m;j++)s[i].push_back(s1[j]);
	}
	int l=0,r=min(n,m);
	while (l<r){
		int mid=(l+r+1)/2;
		if (pd(mid))l=mid;
		else r=mid-1;
	}
	printf("%d\n",l);
	solve(l);
}