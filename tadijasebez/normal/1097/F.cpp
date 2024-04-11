#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=100050;
const int V=7005;
bitset<V> st[N],ds[V],tmp,zy[V];
int main()
{
	int n,q,i,j;
	vector<int> good;
	for(i=1;i<V;i++)
	{
		for(j=1;j*j<=i;j++)
		{
			if(i%j==0)
			{
				ds[i].set(j);
				ds[i].set(i/j);
			}
		}
		bool ok=1;
		for(j=2;j*j<=i;j++)
		{
			if(i%(j*j)==0) ok=0;
		}
		if(ok) good.pb(i);
	}
	for(i=1;i<V;i++)
	{
		for(j=0;j<good.size();j++)
		{
			if(i*good[j]<V) zy[i].set(i*good[j]);
		}
	}
	scanf("%i %i",&n,&q);
	while(q--)
	{
		int t,x,y,z,v;
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i",&x,&v);
			st[x]=ds[v];
			//st[x]=0;
			//st[x].set(v);
		}
		else if(t==2)
		{
			scanf("%i %i %i",&x,&y,&z);
			st[x]=st[y]^st[z];
		}
		else if(t==3)
		{
			scanf("%i %i %i",&x,&y,&z);
			st[x]=st[y]&st[z];
			/*tmp=0;
			//if(st[y].count()>st[z].count()) swap(y,z);
			//printf("st[y][4]=%i %i\n",st[y].test(4),y);
			//for(int i=1;i<=7000;i++) if(st[y].test(i))
			for(int i=7000;i>=1;i--)
			{
				/*for(int j=1;j<=7000;j++) if(st[z].test(j))
				{
					int g=__gcd(i,j);
					tmp.flip(g);
				}*//*
				int a=0,b=0;
				for(int j=i;j<=7000;j+=i)
				{
					if(tmp.test(j)) tmp.flip(i);
					a^=st[y].test(j);
					//if(i==4 && st[y].test(j)) printf("j:%i ",j);
					b^=st[z].test(j);
				}
				//if(i==4) printf("a:%i b:%i %i\n",a,b,tmp.test(i));
				a&=b;
				if(a) tmp.flip(i);
			}
			st[x]=tmp;*/
		}
		else
		{
			scanf("%i %i",&x,&v);
			int ans=(st[x]&zy[v]).count()&1;
			/*int sz=(V-1)/v;
			if(v==1)
			{
				ans=st[x].count();
			}
			else
			{
				for(int i=1;i<=sz;i++) ans^=st[x].test(i*v);
			}
			for(int i=0;i<bad.size() && bad[i]<=sz;i++) ans^=st[x].test(bad[i]);*/
			printf("%i",ans);
		}
		//printf("\n");for(int i=1;i<=6;i++) printf("%i",st[x].test(i));printf("\n");
	}
	return 0;
}