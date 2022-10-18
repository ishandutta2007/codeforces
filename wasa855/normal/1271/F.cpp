#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int ta1,ta2,ta3;
int tb1,tb2,tb3;
int d1,d2,d3,d4,d5,d6,d7;
void work()
{
	cin>>ta1>>ta2>>ta3;
	cin>>tb1>>tb2>>tb3;
	cin>>d1>>d2>>d3>>d4>>d5>>d6>>d7;
	bool ok=0;
	for(int i=0;i<=d2;i++)  //use d2
	{
		for(int j=0;j<=d3;j++) //use d3
		{
			int a1=ta1,a2=ta2,a3=ta3;
			int b1=tb1,b2=tb2,b3=tb3;
			a1-=i,a2-=i,a1-=j,a3-=j;
			b1-=(d2-i),b2-=(d2-i),b1-=(d3-j),b3-=(d3-j);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			int u1=min(d1,min(a1,min(a2,a3)));
			a1-=u1,a2-=u1,a3-=u1;
			b1-=(d1-u1),b2-=(d1-u1),b3-=(d1-u1);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			int u4=min(d4,a1);
			a1-=u4;
			b1-=(d4-u4);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			int u5=min(d5,min(a2,a3));
			a2-=u5,a3-=u5;
			b2-=(d5-u5),b3-=(d5-u5);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			int u6=min(d6,a2);
			a2-=u6;
			b2-=(d6-u6);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			int u7=min(d7,a3);
			a3-=u7;
			b3-=(d7-u7);
			if(a1<0||a2<0||a3<0||b1<0||b2<0||b3<0)
			{
				continue;
			}
			printf("%d %d %d %d %d %d %d\n",u1,i,j,u4,u5,u6,u7);
			ok=1;
			break;
		}
		if(ok) break;
	}
	if(!ok) cout<<"-1\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//