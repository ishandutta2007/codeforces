#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,m,s[6][6],e[N],d1[N],d2[N],a1[N],a2[N],mp[N],vis[N],a[N],b[N],ra[N],rb[N];
vector<vector<int>>p1,p2;
vector<string>g1,g2;
int t1(int x,int y){return x<=2?(x-1)*n+y:2*n+(x-3)*m+y;}
pair<int,int>t2(int x){return (x<=2*n)?make_pair((x-1)/n+1,(x-1)%n+1):make_pair(2+(x-2*n-1)/m+1,(x-2*n-1)%m+1);}
void ad(int x,int y){e[x]=y,e[y]=x;}
void no(){puts("No solution");exit(0);}
int cal(int *s,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		int t=(s[(i+k)%n]-s[(j+k)%n]);
		if(!t)
			k++;
		else
		{
			if(t>0)
				i+=k+1;
			else
				j+=k+1;
			if(i==j)
				j++;
			k=0;
		}
	}
	return min(i,j);
}
void sol(vector<vector<int>>&p,vector<string>&g)
{
	for(int i=1;i<=(n+m)*2;i++)
		vis[i]=0;
	for(int i=1;i<=(n+m)*2;i++)
	{
		if(!vis[i])
		{
			int j=i,k,l=0;
			do
			{
				vis[j]=1;
				a[l]=t2(j).first,b[l]=j,l++;
				k=e[j],vis[k]=1;
				auto y=t2(k);
				a[l]=y.first,b[l]=k,l++;
				y.first+=y.first&1?1:-1;
				j=t1(y.first,y.second);
			}while(j!=i);
			for(int j=0;j<l;j++)
				ra[j]=a[l-j-1],rb[j]=b[l-j-1];
			int p1=cal(a,l),p2=cal(ra,l);
			string s1="",s2="";
			for(int j=0;j<l;j++)
			{
				s1.push_back((char)(a[(p1+j)%l]+'a'));
				s2.push_back((char)(ra[(p2+j)%l]+'a'));
			}
			if(s1<s2)
			{
				p.push_back(vector<int>());
				g.push_back(s1);
				for(int j=0;j<l;j++)
					p.back().push_back(b[(p1+j)%l]);
			}
			else
			{
				p.push_back(vector<int>());
				g.push_back(s2);
				for(int j=0;j<l;j++)
					p.back().push_back(rb[(p2+j)%l]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	mp['L']=1,mp['R']=2,mp['T']=3,mp['B']=4;
	cin>>n>>m;
	for(int i=1;i<=n+m;i++)
	{
		int a,b;
		char c,d;
		cin>>c>>d>>a>>b;
		c=mp[c],d=mp[d];
		ad(t1(c,a),t1(d,b));
		s[min(c,d)][max(c,d)]++;
	}
	if(s[1][2]&&s[3][4])
		no();
	if(s[1][3]^s[2][4])
		no();
	if(s[1][4]^s[2][3])
		no();
	sol(p1,g1);
	for(int i=1;i<=s[1][3];i++)
		ad(t1(1,i),t1(3,i));
	for(int i=1;i<=s[2][3];i++)
		ad(t1(2,i),t1(3,m-i+1));
	for(int i=1;i<=s[1][4];i++)
		ad(t1(1,n-i+1),t1(4,i));
	for(int i=1;i<=s[2][4];i++)
		ad(t1(2,n-i+1),t1(4,m-i+1));
	for(int i=1;i<=s[1][2];i++)
		ad(t1(1,s[1][3]+i),t1(2,s[2][3]+i));
	for(int i=1;i<=s[3][4];i++)
		ad(t1(3,s[1][3]+i),t1(4,s[1][4]+i));
	sol(p2,g2);
	if(p1.size()!=p2.size())
		no();
	int k=p1.size();
	for(int i=0;i<k;i++)
		d1[i]=d2[i]=i;
	sort(d1,d1+k,[&](int x,int y){return g1[x]<g1[y];});
	sort(d2,d2+k,[&](int x,int y){return g2[x]<g2[y];});
	for(int i=0;i<k;i++)
	{
		if(g1[d1[i]]!=g2[d2[i]])
			no();
		for(int j=0;j<g1[d1[i]].size();j++)
		{
			int w=t2(p2[d2[i]][j]).first,x=t2(p1[d1[i]][j]).second,y=t2(p2[d2[i]][j]).second;
			if(w==1)
				a1[y]=x;
			if(w==3)
				a2[y]=x;
		}
	}
	for(int i=1;i<=n;i++)
		cout<<a1[i]<<' ';
	cout<<endl;
	for(int i=1;i<=m;i++)
		cout<<a2[i]<<' ';
	return 0;
}