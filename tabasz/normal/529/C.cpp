#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back
#define PII pair<int, int>
const int M=1024*128;


struct event
{
	int ind, p, k, num;
};

struct area
{
	int x1, x2, y1, y2;
};

int n, m, k, l;
bool B[2*M];
area T[2][2*M];
vector<event> V[2];
int D[2][2*M];

bool cmp(event x, event y)
{
	if(x.ind==y.ind) return x.num<y.num;
	return x.ind<y.ind;
}

void add(int ind, int v, int w)
{
	v+=M;
	D[ind][v]=max(D[ind][v], w);
	while(v>1)
	{
		v/=2;
		D[ind][v]=min(D[ind][2*v], D[ind][2*v+1]);
	}
}

int mini(int ind, int v, int vp, int vk, int p, int k)
{
	if(vp>k || vk<p) return 1000000000;
	if(vp>=p && vk<=k) return D[ind][v];
	int mid=(vp+vk)/2;
	return min(mini(ind, 2*v, vp, mid, p, k), mini(ind, 2*v+1, mid+1, vk, p, k));
}

void jebaj(int in)
{
	sort(V[in].begin(), V[in].end(), cmp);
	for(int i=0; i<(int)V[in].size(); i++)
	{
		if(V[in][i].num==-1)
		{
			add(in, V[in][i].p, V[in][i].ind);
			//if(in==1) printf("lol %d %d\n", V[in][i].p, V[in][i].ind);
		}
		else
		{
			int qwe=mini(in, 1, 0, M-1, V[in][i].p, V[in][i].k);
			int asd=T[in][V[in][i].num].y1;
			//if(in==1) printf("%d %d %d %d %d\n", V[in][i].ind, qwe, asd, V[in][i].p, V[in][i].k);
			if(qwe>=asd) B[V[in][i].num]=1;
		}
	}
}

int main()
{
	//ios_base:sync_with_stdio(0);
	scanf("%d%d%d%d", &n, &m, &k, &l);
	for(int i=0; i<k; i++)
	{
		event x;
		scanf("%d%d", &x.p, &x.ind);
		x.num=-1;
		V[0].PB(x);
		swap(x.ind, x.p);
		V[1].PB(x);
	}
	for(int i=0; i<l; i++)
	{
		area x;
		scanf("%d%d%d%d", &x.x1, &x.y1, &x.x2, &x.y2);
		T[0][i]=x;
		event y;
		y.ind=x.y2;
		y.p=x.x1;
		y.k=x.x2;
		y.num=i;
		V[0].PB(y);
		swap(x.x1, x.y1);
		swap(x.x2, x.y2);
		T[1][i]=x;
		y.ind=x.y2;
		y.p=x.x1;
		y.k=x.x2;
		V[1].PB(y);
	}
	jebaj(0);
	jebaj(1);
	for(int i=0; i<l; i++)
	{
		if(B[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}