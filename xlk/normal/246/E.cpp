#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef pair<int,int>ii;
const int N=200020;
vector<int>p[N],a[N];
map<pair<int,ii>,int>g;
int c,n,m,x,y,d[N],l[N],r[N];
string s[N];
void fs(int x,int y)
{
	p[y].push_back(x);
	l[x]=c++,d[x]=y;
	for(int&i:a[x])
		fs(i,y+1);
	r[x]=c;
}
int Q(int x,int y)
{
	return lower_bound(p[x].begin(),p[x].end(),y,[](int x,int y){return l[x]<y;})-p[x].begin();
}
int wk(int x,int y)
{
	y+=d[x];
	int L=Q(y,l[x]),R=Q(y,r[x]);
	set<string>q;
	int &t=g[make_pair(y,ii(L,R))];
	if(t)
		return t;
	for(int i=L;i<R;i++)
		q.insert(s[p[y][i]]);
	return t=q.size();
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i]>>x,a[x].push_back(i);
	fs(0,0);
	for(cin>>m;m--;)
		cin>>x>>y,cout<<wk(x,y)<<endl;
}