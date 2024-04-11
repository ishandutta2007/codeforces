#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<math.h>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define D double
const int M=131072;

struct tree
{
	LL s;
	int m, i;
};

tree T[2*M];

void add(int i, int w)
{
	i+=M;
	T[i].s=w;
	T[i].m=w;
	T[i].i=i-M;
	while(i>1)
	{
		i/=2;
		T[i].s=T[2*i].s+T[2*i+1].s;
		T[i].m=max(T[2*i].m, T[2*i+1].m);
		if(T[2*i].m>T[2*i+1].m) T[i].i=T[2*i].i;
		else T[i].i=T[2*i+1].i;
	}
}

pair<int, int> maxi(int v, int vp, int vk, int p, int k)
{
	if(vk<p || vp>k) return MP(-1, -1);
	if(vp>=p && vk<=k) return MP(T[v].m, T[v].i);
	int mid=(vp+vk)/2;
	pair<int, int> a=maxi(2*v, vp, mid, p, k), b=maxi(2*v+1, mid+1, vk, p, k);
	if(a.F>b.F) return a;
	else return b;
}

LL sum(int v, int vp, int vk, int p, int k)
{
	if(vk<p || vp>k) return 0;
	if(vp>=p && vk<=k) return T[v].s;
	int mid=(vp+vk)/2;
	return sum(2*v, vp, mid, p, k)+sum(2*v+1, mid+1, vk, p, k);
}


int main()
{
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>> n >> m;
	for(int i=0; i<n; i++)
	{
		int a;
		cin>> a;
		add(i, a);
	}
	for(int i=0; i<m; i++)
	{
		int x, a, b, c;
		cin>> x >> a >> b;
		if(x==1) cout<< sum(1, 0, M-1, a-1, b-1) << '\n';
		if(x==2)
		{
			cin>> c;
			pair<int, int> w=maxi(1, 0, M-1, a-1, b-1);
			while(w.F>=c)
			{
				add(w.S, w.F%c);
				w=maxi(1, 0, M-1, a-1, b-1);
			}
		}
		if(x==3) add(a-1, b);
	}
	return 0;
}