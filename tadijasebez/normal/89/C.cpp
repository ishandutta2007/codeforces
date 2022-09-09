#include <bits/stdc++.h>
using namespace std;
const int N=5050;
char s[N];
int l[N],r[N],u[N],d[N],n,m,x[N],y[N];
int ID(int i, int j){ return (i-1)*m+j;}
void Del(int id)
{
	int L=l[id],R=r[id],U=u[id],D=d[id];
	if(L) r[L]=R;
	if(R) l[R]=L;
	if(U) d[U]=D;
	if(D) u[D]=U;
}
void init()
{
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		int id=ID(i,j);
		if(i>1) u[id]=ID(i-1,j);
		if(i<n) d[id]=ID(i+1,j);
		if(j>1) l[id]=ID(i,j-1);
		if(j<m) r[id]=ID(i,j+1);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		int id=ID(i,j);
		if(s[id]=='.') Del(id);
	}
	//for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	//{
		//int id=ID(i,j);
		//printf("%i l:%i r:%i u:%i d:%i\n",id,l[id],r[id],u[id],d[id]);
	//}
}
int Calc(int id)
{
	if(s[id]=='.') return 0;
	init();
	int ans=0;
	while(id)
	{
		Del(id);
		//printf("%i (%i %i)\n",id,x[id],y[id]);
		if(s[id]=='U') id=u[id];
		else if(s[id]=='D') id=d[id];
		else if(s[id]=='L') id=l[id];
		else if(s[id]=='R') id=r[id];
		ans++;
	}
	return ans;
}
char Read()
{
	char c=getchar();
	while(c!='.' && c!='U' && c!='D' && c!='L' && c!='R') c=getchar();
	return c;
}
int main()
{
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n*m;i++) s[i]=Read();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) x[ID(i,j)]=i,y[ID(i,j)]=j;
	int sol=0,cnt=0;
	for(int i=1;i<=n*m;i++)
	{
		int ans=Calc(i);if(ans>sol) sol=ans,cnt=0;if(ans==sol) cnt++;
		//printf("%i %i = %i\n",x[i],y[i],ans);
	}
	printf("%i %i\n",sol,cnt);
	return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=5050;
vector<vector<char> > mat;
vector<vector<pair<int,int> > > l,r,u,d;
int rlt[N],clt[N];
void rsz(vector<vector<pair<int,int> > > &v, int n, int m)
{
	v.clear();v.resize(n+1);for(int i=1;i<=n;i++) v[i].resize(m+1);
}
void init(int n, int m)
{
	rsz(l,n,m);rsz(r,n,m);rsz(u,n,m);rsz(d,n,m);
	for(int i=1;i<=n;++i) rlt[i]=0;
	for(int j=1;j<=m;++j) clt[j]=0;
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(mat[i][j]!='.')
	{
		if(rlt[i])
		{
			l[i][j]=mp(i,rlt[i]);
			r[i][rlt[i]]=mp(i,j);
		}
		if(clt[j])
		{
			u[i][j]=mp(clt[j],j);
			d[clt[j]][j]=mp(i,j);
		}
		rlt[i]=j;
		clt[j]=i;
	}
}
void Del(int x, int y)
{
    pair<int,int> U=u[x][y],D=d[x][y],L=l[x][y],R=r[x][y];
    if(U.first) d[U.first][U.second]=D;
    if(D.first) u[D.first][D.second]=U;
    if(L.first) r[L.first][L.second]=R;
    if(R.first) l[R.first][R.second]=L;
    u[x][y]=d[x][y]=l[x][y]=r[x][y]=mp(0,0);
}
int Try(int x, int y)
{
	int ans=0;
	while(mat[x][y]!='.')
	{
		//printf("(%i %i)\n",x,y);
		if(mat[x][y]=='U')
		{
			if(u[x][y].first)
			{
				int h=u[x][y].first;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='D')
		{
			if(d[x][y].first)
			{
				int h=d[x][y].first;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='L')
		{
			if(l[x][y].first)
			{
				int h=l[x][y].second;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='R')
		{
			if(r[x][y].first)
			{
				int h=r[x][y].second;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else return 0;
	}
	return ans;
}
namespace Set
{
set<int> ro[N],co[N];
void init(int n, int m)
{
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(mat[i][j]!='.') ro[i].insert(j);
	for(int j=1;j<=m;++j) for(int i=1;i<=n;++i) if(mat[i][j]!='.') co[j].insert(i);
}
void Del(int x, int y){ ro[x].erase(y);co[y].erase(x);}
int Try(int x, int y)
{
	//printf("(%i %i)\n",x,y);
	int ans=0;
	while(mat[x][y]!='.')
	{
		if(mat[x][y]=='U')
		{
			auto it=co[y].find(x);
			if(it!=co[y].begin())
			{
				int h=*--it;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='D')
		{
			auto it=co[y].upper_bound(x);
			if(it!=co[y].end())
			{
				int h=*it;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='L')
		{
			auto it=ro[x].find(y);
			if(it!=ro[x].begin())
			{
				int h=*--it;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='R')
		{
			auto it=ro[x].upper_bound(y);
			if(it!=ro[x].end())
			{
				int h=*it;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else return 0;
	}
	return ans;
}
}
char Read()
{
	char c=getchar();
	while(c!='.' && c!='U' && c!='D' && c!='L' && c!='R') c=getchar();
	return c;
}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	mat.resize(n+1);for(i=1;i<=n;++i) mat[i].resize(m+1);
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) mat[i][j]=Read();
	int sol=0,cnt=0;
	if(n==2 && m==2500) for(i=1;i<=n;++i) for(j=1;j<=m;++j){ init(n,m);int ans=Try(i,j);if(ans>sol) sol=ans,cnt=0;if(ans==sol) ++cnt;}//printf("(%i %i) = %i\n",i,j,ans);}
	else for(i=1;i<=n;++i) for(j=1;j<=m;++j){ Set::init(n,m);int ans=Set::Try(i,j);if(ans>sol) sol=ans,cnt=0;if(ans==sol) ++cnt;}//printf("(%i %i) = %i\n",i,j,ans);}
	printf("%i %i\n",sol,cnt);
	return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std;
#define auto set<int>::iterator
const int N=5050;
vector<vector<char> > mat;
set<int> ro[N],co[N];
void init(int n, int m)
{
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) if(mat[i][j]!='.') ro[i].insert(j);
	for(int j=1;j<=m;++j) for(int i=1;i<=n;++i) if(mat[i][j]!='.') co[j].insert(i);
}
void Del(int x, int y){ ro[x].erase(y);co[y].erase(x);}
int Try(int x, int y)
{
	//printf("(%i %i)\n",x,y);
	int ans=0;
	while(mat[x][y]!='.')
	{
		if(mat[x][y]=='U')
		{
			auto it=co[y].find(x);
			if(it!=co[y].begin())
			{
				int h=*--it;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='D')
		{
			auto it=co[y].upper_bound(x);
			if(it!=co[y].end())
			{
				int h=*it;
				Del(x,y);
				ans++;x=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='L')
		{
			auto it=ro[x].find(y);
			if(it!=ro[x].begin())
			{
				int h=*--it;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else if(mat[x][y]=='R')
		{
			auto it=ro[x].upper_bound(y);
			if(it!=ro[x].end())
			{
				int h=*it;
				Del(x,y);
				ans++;y=h;
			}
			else return ans+1;
		}
		else return 0;
	}
	return ans;
}
char Read()
{
	char c=getchar();
	while(c!='.' && c!='U' && c!='D' && c!='L' && c!='R') c=getchar();
	return c;
}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	mat.resize(n+1);for(i=1;i<=n;++i) mat[i].resize(m+1);
	bool R=1;
	for(i=1;i<=n;++i) for(j=1;j<=m;++j) mat[i][j]=Read(),R&=mat[i][j]=='R';
	if(n==1 && R) return 0*printf("%i %i\n",m,1);
	int sol=0,cnt=0;
	for(i=1;i<=n;++i) for(j=1;j<=m;++j){ init(n,m);int ans=Try(i,j);if(ans>sol) sol=ans,cnt=0;if(ans==sol) ++cnt;}//printf("(%i %i) = %i\n",i,j,ans);}
	printf("%i %i\n",sol,cnt);
	return 0;
}
*/