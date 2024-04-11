#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=305;
const int M=100050;
string a[N][N],b[N][N];
deque<char> tmp[N][N];
deque<int> one,zero;
int work[N][N];
char s[M];
int cnt[N][N];
vector<pair<pair<int,int> , pair<int,int> > > ans;
void Move(int x, int y, int a, int b)
{
	//printf("Move %i %i to %i %i\n",x,y,a,b);
	if(x==a && y==b)
	{
		if(x==1) ans.pb(mp(mp(x,y),mp(x,y+1))),ans.pb(mp(mp(x,y+1),mp(x,y)));
		else ans.pb(mp(mp(x,y),mp(x,y-1))),ans.pb(mp(mp(x,y-1),mp(x,y)));
	}
	else if(x==a || y==b) ans.pb(mp(mp(x,y),mp(a,b)));
	else
	{
		if(!cnt[x][b]) ans.pb(mp(mp(x,y),mp(x,b))),ans.pb(mp(mp(x,b),mp(a,b)));
		else ans.pb(mp(mp(x,y),mp(a,y))),ans.pb(mp(mp(a,y),mp(a,b)));
	}
	cnt[x][y]--;
	cnt[a][b]++;
}
int main()
{
	int n,m,i,j,k,z=0,o=0,len;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(k=0;k<len;k++) a[i][j]+=s[k];
		cnt[i][j]=len;
		/*if(!((i==1 && j==1) || (i==n && j==m)))
		{
			for(k=len-1;k>=0;k--)
			{
				if(s[k]=='0')
				{
					Move(i,j,1,1);
					//tmp[1][1].push_front(s[k]);
					z++;
				}
				else
				{
					Move(i,j,n,m);
					o++;
				}
			}
		}*/
		//else
		//{
		//	for(k=len-1;k>=0;k--)
		//	{
		//		tmp[1][1].push_front(s[k]);
		//	}
		//}
	}
	i=n;j=1;
	len=a[i][j].size();
	for(k=len-1;k>=0;k--)
	{
		if(a[i][j][k]=='0')
		{
			Move(i,j,1,1);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(i,j,n,m);
			o++;
		}
	}
	i=1;j=m;
	len=a[i][j].size();
	for(k=len-1;k>=0;k--)
	{
		if(a[i][j][k]=='0')
		{
			Move(i,j,1,1);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(i,j,n,m);
			o++;
		}
	}
	i=1;
	for(j=2;j<m;j++)
	{
		//printf("solve %i %i\n");
		len=a[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(a[i][j][k]=='0')
			{
				Move(i,j,1,1);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(i,j,n,m);
				o++;
			}
		}
	}
	i=n;
	for(j=2;j<m;j++)
	{
		len=a[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(a[i][j][k]=='0')
			{
				Move(i,j,1,1);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(i,j,n,m);
				o++;
			}
		}
	}
	j=1;
	for(i=2;i<n;i++)
	{
		len=a[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(a[i][j][k]=='0')
			{
				Move(i,j,1,1);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(i,j,n,m);
				o++;
			}
		}
	}
	j=m;
	for(i=2;i<n;i++)
	{
		len=a[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(a[i][j][k]=='0')
			{
				Move(i,j,1,1);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(i,j,n,m);
				o++;
			}
		}
	}
	for(i=2;i<n;i++) for(j=2;j<m;j++)
	{
		len=a[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(a[i][j][k]=='0')
			{
				Move(i,j,1,1);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(i,j,n,m);
				o++;
			}
		}
	}
	len=a[1][1].size();
	for(k=len-1;k>=0;k--)
	{
		if(a[1][1][k]=='0')
		{
			Move(1,1,1,1);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(1,1,n,m);
			o++;
		}
	}
	len=a[n][m].size();
	for(k=len-1;k>=0;k--)
	{
		if(a[n][m][k]=='0')
		{
			Move(n,m,1,1);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(n,m,n,m);
			o++;
		}
	}
	for(i=1;i<=n;i++) for(j=1;j<=m;j++)
	{
		scanf("%s",s);
		int len=strlen(s);
		for(k=0;k<len;k++) b[i][j]+=s[k];
		work[i][j]=(int)b[i][j].size()-1;
		/*if(work[i][j]>=0 && (!((i==1 && j==1) || (i==n && j==m))))
		{
			if(b[i][j][work[i][j]]=='0')
			{
				zero.push_back(i*N+j);
			}
			else one.push_back(i*N+j);
		}*/
	}
	len=b[1][1].size();
	for(k=len-1;k>=0;k--)
	{
		if(b[1][1][k]=='0')
		{
			Move(1,1,1,1);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(n,m,1,1);
			o++;
		}
	}
	len=b[n][m].size();
	for(k=len-1;k>=0;k--)
	{
		if(b[n][m][k]=='0')
		{
			Move(1,1,n,m);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(n,m,n,m);
			o++;
		}
	}
	for(i=2;i<n;i++) for(j=2;j<m;j++)
	{
		//printf("solve:%i %i\n",i,j);
		len=b[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(b[i][j][k]=='0')
			{
				Move(1,1,i,j);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(n,m,i,j);
				o++;
			}
		}
	}
	i=1;
	for(j=2;j<m;j++)
	{
		//printf("solve %i %i\n");
		len=b[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(b[i][j][k]=='0')
			{
				Move(1,1,i,j);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(n,m,i,j);
				o++;
			}
		}
	}
	i=n;
	for(j=2;j<m;j++)
	{
		len=b[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(b[i][j][k]=='0')
			{
				Move(1,1,i,j);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(n,m,i,j);
				o++;
			}
		}
	}
	j=1;
	for(i=2;i<n;i++)
	{
		len=b[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(b[i][j][k]=='0')
			{
				Move(1,1,i,j);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(n,m,i,j);
				o++;
			}
		}
	}
	j=m;
	for(i=2;i<n;i++)
	{
		len=b[i][j].size();
		for(k=len-1;k>=0;k--)
		{
			if(b[i][j][k]=='0')
			{
				Move(1,1,i,j);
				//tmp[1][1].push_front(s[k]);
				z++;
			}
			else
			{
				Move(n,m,i,j);
				o++;
			}
		}
	}
	i=n;j=1;
	len=b[i][j].size();
	for(k=len-1;k>=0;k--)
	{
		if(b[i][j][k]=='0')
		{
			Move(1,1,i,j);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(n,m,i,j);
			o++;
		}
	}
	i=1;j=m;
	len=b[i][j].size();
	for(k=len-1;k>=0;k--)
	{
		if(b[i][j][k]=='0')
		{
			Move(1,1,i,j);
			//tmp[1][1].push_front(s[k]);
			z++;
		}
		else
		{
			Move(n,m,i,j);
			o++;
		}
	}
	/*while(zero.size() || one.size())
	{
		if(zero.size())
		{
			int x=zero.front()/N;
			int y=zero.front()%N;
			printf("zero:%i %i\n",x,y);
			zero.pop_front();
			Move(1,1,x,y);
			work[x][y]--;
			if(work[x][y]>=0)
			{
				if(b[x][y][work[x][y]]=='0')
				{
					zero.push_back(x*N+y);
				}
				else one.push_back(x*N+y);
			}
		}
		else
		{
			int x=one.front()/N;
			int y=one.front()%N;
			printf("one:%i %i\n",x,y);
			one.pop_front();
			Move(n,n,x,y);
			work[x][y]--;
			if(work[x][y]>=0)
			{
				if(b[x][y][work[x][y]]=='0')
				{
					zero.push_back(x*N+y);
				}
				else one.push_back(x*N+y);
			}
		}
	}*/
	printf("%i\n",ans.size());
	for(i=0;i<ans.size();i++)
		printf("%i %i %i %i\n",ans[i].first.first,ans[i].first.second,ans[i].second.first,ans[i].second.second);
	/*while(tmp[1][1].size())
	{
		if(tmp[1][1].back()=='1')
		{
			if(work[1][1]>=0 && b[1][1][work[1][1]]=='1')
			{
				Move(1,1,1,2);
				//tmp[1][2].push_front('1');
				work[1][1]--;
				if(work[1][1]>=0)
				{
					if(b[1][1][work[1][1]]=='0') zero.push_back(1*N+1);
					else one.push_back(1*N+1);
				}
			}
            else
			{
                int x=one.front()/N;
                int y=one.front()%N;
                one.pop_front();
                if(x==1 && y==2)
				{
					one.push_back(x*N+y);
					x=one.front()/N;
					y=one.front()%N;
					one.pop_front();
				}
                Move(1,1,x,y);
                work[x][y]--;
                if(work[x][y]>=0)
				{
					if(b[x][y][work[x][y]]=='0')
					{
						zero.push_back(x*N+y);
					}
					else one.push_back(x*N+y);
				}
			}
		}
		else
		{
			if(work[1][1]>=0 && b[1][1][work[1][1]]=='0')
			{
				Move(1,1,1,2);
				//tmp[1][2].push_front('0');
				work[1][1]--;
				if(work[1][1]>=0)
				{
					if(b[1][1][work[1][1]]=='0') zero.push_back(1*N+1);
					else one.push_back(1*N+1);
				}
			}
            else
			{
                int x=zero.front()/N;
                int y=zero.front()%N;
                zero.pop_front();
                if(x==1 && y==2)
				{
					zero.push_back(x*N+y);
					x=zero.front()/N;
					y=zero.front()%N;
					zero.pop_front();
				}
                Move(1,1,x,y);
                work[x][y]--;
                if(work[x][y]>=0)
				{
					if(b[x][y][work[x][y]]=='0')
					{
						zero.push_back(x*N+y);
					}
					else one.push_back(x*N+y);
				}
			}
		}
		tmp[1][1].pop_back();
	}*/
	return 0;
}