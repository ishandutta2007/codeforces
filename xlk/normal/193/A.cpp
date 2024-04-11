#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int> ii;
queue<ii>q;
char s[60][60];
int a[60][60];
int b[60][60];
int v[60][60];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int n,m,cnt;
int ok()
{
	int num=0;
	memset(v,0,sizeof v);
	fo(i,n)
		fo(j,m)
			if(s[i][j]=='#')
			{
				q.push(ii(i,j));
				v[i][j]=1;
				num=1;
				goto st;
			}
	st:
	while(q.size())
	{
		ii u=q.front();
		q.pop();
		fr(i,4)
		{
			if(s[u.X+dx[i]][u.Y+dy[i]]=='#'&&!v[u.X+dx[i]][u.Y+dy[i]])
			{
				q.push(ii(u.X+dx[i],u.Y+dy[i]));
				v[u.X+dx[i]][u.Y+dy[i]]=1;
				num++;
			}
		}
	}
	return num!=cnt-1;
}
int main()
{
	scanf("%d %d",&n,&m);
	fo(i,n)
		scanf("%s",s[i]+1);
//	fr(i,n+3)
//		fr(j,m+3)
//			a[i][j]=0xffff;
	fo(i,n)
		fo(j,m)
		{
			a[i][j]=s[i][j]=='#';
			cnt+=s[i][j]=='#';
		}
	fo(i,n)
		fo(j,m)
			fr(k,4)
				b[i][j]+=a[i+dx[k]][j+dy[k]];
	int z=0xffff;
	fo(i,n)
		fo(j,m)
			if(s[i][j]=='#'&&b[i][j]<z)
				z=b[i][j];
	if(cnt<3)
		puts("-1");
	else
	{
		fo(i,n)
			fo(j,m)
				if(s[i][j]=='#')
				{
					s[i][j]='.';
					if(ok())
						z=min(z,1);
					s[i][j]='#';
				}
		printf("%d",z);
	}
}