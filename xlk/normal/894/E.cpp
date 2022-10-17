#include <bits/stdc++.h>
using namespace std;
int dfn[1000020],low[1000020];
vector<pair<int, int> >b[1000020];
vector<pair<int, int> >a[1000020];
int cnt,ss;
int s[1000020];
int sum[1000020];
int v[1000020];
int r[1000020];
int ao,ai,scc,n,m;
int out[1000020],in[1000020];
int u[1000020];
long long value[1000020];
long long f[1000020];
long long ans = 0;
void tarjan(int x)
{
	int y,i,j;
	cnt++;
	dfn[x]=low[x]=cnt;
	v[x]=1;
	s[ss++]=x;
	for(i=0;i<b[x].size();i++) {
		if(dfn[b[x][i].first]==0) {
			tarjan(b[x][i].first);
			if(low[x]>low[b[x][i].first]) {
				low[x]=low[b[x][i].first];
			}
		} else if(v[b[x][i].first]==1&&low[x]>dfn[b[x][i].first]) {
			low[x]=dfn[b[x][i].first];
		}
	}
	if(dfn[x]==low[x]) {
		scc++;
		do {
			y=s[--ss];
			r[y]=scc;
			v[y]=0;
		} while(x!=y);
	}
}
long long F(int x) {
	if(f[x] != -1) {
		return f[x];
	}
	f[x] = 0;
	for(int i=0;i<a[x].size();i++) {
		f[x]=max(f[x], F(a[x][i].first) + a[x][i].second);
	}
	return f[x] += value[x];
}
long long fuck(int x) {
	int rt = sqrt(2 * x);
	while ((long long)rt * (rt - 1) / 2 <= x) {
		rt++;
	}
	while ((long long)rt * (rt - 1) / 2 > x) {
		rt--;
	}
	return (long long)rt * x - (long long)(rt + 1) * rt * (rt - 1) / 6;
}
int main()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		b[x].push_back(make_pair(y, z));
	}
	int ssss;
	scanf("%d", &ssss);
	tarjan(ssss);
	for(i=1;i<=n;i++)
		for(j=0;j<b[i].size();j++)
		{
			if(r[i]==r[b[i][j].first]) {
				value[r[i]] += fuck(b[i][j].second);
			} else {
				out[r[i]]++,in[r[b[i][j].first]]++;
				a[r[i]].push_back(make_pair(r[b[i][j].first], b[i][j].second));
			}
		}
	memset(f, -1, sizeof f);
	printf("%lld\n", F(r[ssss]));
	return 0;
}