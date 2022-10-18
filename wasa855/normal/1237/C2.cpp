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
#define N 50005
struct Node
{
	int x,y,z;
	int id;
};
Node a[N];
bool cmp(Node x,Node y)
{
	if(x.x!=y.x) return x.x<y.x;
	if(x.y!=y.y) return x.y<y.y;
	return x.z<y.z;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i].x=read(),a[i].y=read(),a[i].z=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	vector<Node> res;
	for(int l=1,r;l<=n;l=r+1)
	{
		r=l;
		while(r<n&&a[r+1].x==a[l].x) r++;
//		printf("%d %d\n",l,r);
		vector<Node> ll;
		for(int _l=l,_r;_l<=r;_l=_r+1)
		{
			_r=_l;
			while(_r<r&&a[_r+1].y==a[_l].y) _r++;
//			printf("** %d %d\n",_l,_r);
			int i;
			for(i=_l;i+1<=_r;i+=2)
			{
				printf("%d %d\n",a[i].id,a[i+1].id);
			}
			if(i==_r) ll.pb(a[_r]);
		}
		int siz=ll.size();
//		cout<<"**- "<<siz<<endl;
		int i;
		for(i=0;i+1<siz;i+=2)
		{
			printf("%d %d\n",ll[i].id,ll[i+1].id);
		}
		if(siz&1) res.pb(ll.back());
	}
	int siz=res.size();
	for(int i=0;i+1<siz;i+=2)
	{
		printf("%d %d\n",res[i].id,res[i+1].id);
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}