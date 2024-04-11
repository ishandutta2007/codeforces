#include<bits/stdc++.h>
#define maxn 300005
using namespace std;
int n;
int pos[maxn],col[maxn];
vector<int> R,B;
int main()
{
	scanf("%d",&n);
	bool hasG=0;
	for(int i=1;i<=n;++i)
	{
		char op[2];
		scanf("%d",&pos[i]);
		scanf("%s",op);
		if(op[0]=='G')col[i]=0,hasG=1;
		if(op[0]=='R')col[i]=1;
		if(op[0]=='B')col[i]=2;
	}
	if(!hasG)
	{
		for(int i=1;i<=n;++i)
		{
			if(col[i]==1)R.push_back(pos[i]);
			else B.push_back(pos[i]);
		}
		int ans=0;
		if(R.size())ans+=R[R.size()-1]-R[0];
		if(B.size())ans+=B[B.size()-1]-B[0];
		printf("%d\n",ans);
	}
	else
	{
		int lastG=0,ans=0;
		for(int i=1;i<=n;++i)
		{
			if(col[i]==1)R.push_back(pos[i]);
			else if(col[i]==2)B.push_back(pos[i]);
			else
			{
				if(!lastG)
				{
					if(R.size())ans+=pos[i]-R[0];
					if(B.size())ans+=pos[i]-B[0];
					lastG=pos[i];
					R.clear();B.clear();
				}
				else
				{
					int len=3*(pos[i]-lastG);
					if(!R.size()&&!B.size())
					{
						len-=2*(pos[i]-lastG);
					}
					else if(!R.size())
					{
						len-=pos[i]-lastG;
						int mx=0;
						for(int i=1;i<B.size();++i)mx=max(mx,B[i]-B[i-1]);
						mx=max(mx,max(B[0]-lastG,pos[i]-B[B.size()-1]));
						len-=mx;
					}
					else if(!B.size())
					{
						len-=pos[i]-lastG;
						int mx=0;
						for(int i=1;i<R.size();++i)mx=max(mx,R[i]-R[i-1]);
						mx=max(mx,max(R[0]-lastG,pos[i]-R[R.size()-1]));
						len-=mx;
					}
					else
					{
						int mx=0;
						for(int i=1;i<B.size();++i)mx=max(mx,B[i]-B[i-1]);
						mx=max(mx,max(B[0]-lastG,pos[i]-B[B.size()-1]));
						len-=mx;
						mx=0;
						for(int i=1;i<R.size();++i)mx=max(mx,R[i]-R[i-1]);
						mx=max(mx,max(R[0]-lastG,pos[i]-R[R.size()-1]));
						len-=mx;
					}
					ans+=min(len,2*(pos[i]-lastG));
					R.clear();B.clear();
					lastG=pos[i];
				}
			}
		}
		if(R.size())ans+=R[R.size()-1]-lastG;
		if(B.size())ans+=B[B.size()-1]-lastG;
		printf("%d\n",ans);
	}
}