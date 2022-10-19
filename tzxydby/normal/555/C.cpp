#include<bits/stdc++.h>
using namespace std;
const int N=4000005;
struct seg
{
	int tr[N],lc[N],rc[N],c=1,rt=1;
	void update(int &k,int l,int r,int a,int b,int v)
	{
		if(a>b)
			return;
		if(!k) k=++c;
		if(l==a&&r==b)
		{
			tr[k]=max(tr[k],v);
			return;
		}
		int mid=l+r>>1;
		if(b<=mid) update(lc[k],l,mid,a,b,v);
		else if(a>mid) update(rc[k],mid+1,r,a,b,v);
		else update(lc[k],l,mid,a,mid,v),update(rc[k],mid+1,r,mid+1,b,v);
	}
	int query(int k,int l,int r,int x)
	{
		if(!k) return 0;
		if(l==r)
			return tr[k];
		int mid=l+r>>1;
		if(x<=mid) return max(tr[k],query(lc[k],l,mid,x));
		else return max(tr[k],query(rc[k],mid+1,r,x));
	}
}t1,t2;
int n,q;
set<int>s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	while(q--)
	{
		int x,y;
		char t;
		cin>>x>>y>>t;
		if(s.count(x))
		{
			cout<<0<<endl;
			continue;
		}
		s.insert(x);
		if(t=='U')
		{
			int p=t1.query(1,1,n,x)+1;
			cout<<y-p+1<<endl;
			t2.update(t2.rt,1,n,p,y,x);
		}
		else
		{
			int p=t2.query(1,1,n,y)+1;
			cout<<x-p+1<<endl;
			t1.update(t1.rt,1,n,p,x,y);
		}
	}
	return 0;
}