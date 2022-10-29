#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define mod 999999999999989
using namespace std;
int a[1505][1505],b[1505][1505],p[1505],qwq[1505][1505],w[1505],vis[1505],to[1505][1505],pos[1505];
long long A[1505],B[1505];
vector <pair<int,int> > v;
vector <int> ans;
int n,m;
const int base=2021;
inline void split(int x)
{
	ans.push_back(x);
	while(1)
	{
		int flag=0;
	//	for(auto t:v) cout << t.first << " " << t.second << '\n';
	//	puts("");
		for(auto t:v)
		{
			if(to[x][t.first]!=to[x][t.second])
			{
				int p=t.first;
				for(int i=t.first+1;i<=t.second;i++)
				{
					if(to[x][i]!=to[x][i-1])
					{
						p=i-1;
						break;
					}
				}
				vector <pair<int,int> > V;
				for(auto X:v) if(X!=t) V.push_back(X);
				else
				{
					if(t.first<=p) V.push_back({t.first,p});
					if(p+1<=t.second) V.push_back({p+1,t.second});
				}
				for(int i=1;i<=m;i++) w[i]-=(qwq[i][t.first]!=qwq[i][t.second])-(qwq[i][t.first]!=qwq[i][p])-(qwq[i][p+1]!=qwq[i][t.second]);
				swap(V,v);
				flag=1;
				break;
			}
		}
		if(!flag) return ;
	}
}
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		    cin >> a[i][j];
			A[i]=(A[i]*base+a[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
		    cin >> b[i][j];
			B[i]=(B[i]*base+b[i][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(A[i]==B[j])
			{
				B[j]=-1,p[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!p[i])
		{
		    puts("-1");
			return 0;
		}
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
			to[j][p[i]]=a[i][j];
		qwq[j][1]=1;
		for(int i=2;i<=n;i++)
		{
			if(to[j][i]>=to[j][i-1]) qwq[j][i]=qwq[j][i-1];
			else qwq[j][i]=i;
		}
	}
	v.push_back({1,n});
	for(int i=1;i<=m;i++)
		if(qwq[i][n]!=1) w[i]=1;
//	for(int i=1;i<=m;i++) cout << w[i] << " ";
//	puts("");
	while(1)
	{
		int flag=0;
		for(int i=1;i<=m;i++)
			if(!w[i]&&!vis[i]) split(i),vis[i]=1,flag=1;
//		for(auto t:v) cout << t.first << " " << t.second << '\n';
//		for(int i=1;i<=m;i++) cout << w[i] << " ";
//		puts("");
		if(!flag) break;
	}
	for(int i=1;i<=n;i++) pos[p[i]]=i;
	for(auto t:v)
	{
		for(int i=t.first+1;i<=t.second;i++)
		{
			if(pos[i]<pos[i-1])
			{
			    puts("-1");
				return 0;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(auto t:ans) cout << t << " ";
	return 0;
}
/*
4 3
1 2 2
2 2 1
3 1 2
4 1 1
 
4 1 1
3 1 2
2 2 1
1 2 2
*/