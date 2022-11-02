#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ct;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		ct=0;
		while(1)
		{
			bool dn=false;
			if(ct==0)
			{
				if(n>1&&m>1)
				{dn=true;n-=2;m-=2;}
				else if(n>0&&m>11)
				{dn=true;n--;m-=12;}
				else if(m>21)
				{dn=true;m-=22;}
			}
			else
			{
				if(m>21)
				{dn=true;m-=22;}
				else if(n>0&&m>11)
				{dn=true;n--;m-=12;}
				else if(n>1&&m>1)
				{dn=true;n-=2;m-=2;}
			}
			if(!dn)
			{
				if(ct==1)puts("Ciel");
				else puts("Hanako");
				break;
			}
			else ct=1-ct;
		}
	}
}