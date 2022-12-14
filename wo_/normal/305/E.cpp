#include<cstdio>
#include<vector>
#include<cstring>
#include<set>

using namespace std;

int g[5050];

set<int> se;

char ch[5050];
bool ok[5050];
int ln;

vector<int> vec;

int get()
{
	int c=0;
	vec.clear();
	for(int i=0;i<ln;i++)
	{
		if(ok[i]==false&&c!=0)
		{
			vec.push_back(c);
	//		printf("%d ",c);
			c=0;
		}
		else if(ok[i]==true) c++;
	}
	//printf("::");
	int grundy=0;
	for(int i=0;i<vec.size();i++) grundy^=g[vec[i]];
	//printf("%d\n",grundy);
	return grundy;
}

int main()
{
	g[0]=0;
	for(int i=1;i<=5000;i++)
	{
		if(i==1) g[1]=1;
		if(i==2) g[2]=1;
		if(i==3) g[3]=2;
		else
		{
			se.clear();
			se.insert(g[i-2]);
			for(int j=0;j<=i-3;j++)
			{
				int tmp=g[j]^g[i-3-j];
				se.insert(tmp);
			}
			int c=0;
			while(se.find(c)!=se.end()) c++;
			g[i]=c;
		}
	}
	scanf("%s",ch);
	ln=strlen(ch);
	for(int i=1;i<ln-1;i++)
	{
		if(ch[i-1]==ch[i+1]) ok[i]=true;
		else ok[i]=false;
	}
	ok[0]=false;ok[ln-1]=false;
	int grundy=get();
	if(grundy==0)
	{
		printf("Second\n");
		return 0;
	}
	else
	{
		printf("First\n");
		int ans=0;
		for(int i=0;i<ln;i++)
		{
			if(ok[i]==true)
			{
				bool tmp[3];
				tmp[0]=ok[i-1];
				tmp[1]=ok[i];
				tmp[2]=ok[i+1];
				for(int j=i-1;j<=i+1;j++) ok[j]=false;
				int g=get();
				ok[i-1]=tmp[0];
				ok[i]=tmp[1];
				ok[i+1]=tmp[2];
	//			printf("a%d %d\n",i,g);
				if(g==0)
				{
					ans=i;
					break;
				}
			}
		}
		printf("%d\n",ans+1);
	}
	return 0;
}