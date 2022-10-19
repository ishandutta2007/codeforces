#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[3][30],m=INT_MAX,t;
char b[N];
vector<pair<int,int>>ans;
vector<int>pa,pb,pc,qa,qb,qc;
void add(vector<int>&x,vector<int>&y)
{
	ans.emplace_back(x.back(),y.back());
	x.pop_back();
	y.pop_back();
}
int main()
{
	for(int i=0;i<3;i++)
	{
		scanf("%s",b+1);
		int n=strlen(b+1);
		m=min(m,n);
		for(int j=1;j<=n;j++)
			a[i][b[j]-'A']++;
	}
	for(int i=0;i<26;i++)
	{
		int x=0,y=0,z=0,c=0;
		for(int tx=0;tx<=a[0][i]&&tx<=a[1][i];tx++)
		{
			for(int ty=0;tx+ty<=a[1][i]&&ty<=a[2][i]&&t+tx+ty<=m;ty++)
			{
				int tz=min(a[0][i]-tx,a[2][i]-ty);
				tz=min(tz,m-tx-ty-t);
				if(tx+ty+tz>c)
				{
					c=tx+ty+tz;
					x=tx;
					y=ty;
					z=tz;
				}
			}
		}
		t+=c;
		pc.insert(pc.end(),x,i);
		a[0][i]-=x;
		a[1][i]-=x;
		pa.insert(pa.end(),y,i);
		a[1][i]-=y;
		a[2][i]-=y;
		pb.insert(pb.end(),z,i);
		a[0][i]-=z;
		a[2][i]-=z;
	}
	for(int i=0;i<26;i++)
	{
		qa.insert(qa.end(),a[0][i],i);
		qb.insert(qb.end(),a[1][i],i);
		qc.insert(qc.end(),a[2][i],i);
	}
	while(pa.size())
		add(pa,qa);
	while(pb.size())
		add(pb,qb);
	while(pc.size())
		add(pc,qc);
	while(qa.size()&&(qb.size()||qc.size()))
	{
		if(qb.size()>qc.size())
			add(qa,qb);
		else
			add(qa,qc);
	}
	while(qb.size()&&qc.size())
		add(qb,qc);
	for(auto i:qa)
		ans.emplace_back(i,0);
	for(auto i:qb)
		ans.emplace_back(i,0);
	for(auto i:qc)
		ans.emplace_back(i,0);
	printf("%d\n",ans.size());
	for(auto [i,j]:ans)
		printf("%c%c\n",'A'+i,'A'+j);
	return 0;
}