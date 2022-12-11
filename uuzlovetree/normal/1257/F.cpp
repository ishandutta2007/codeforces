#include<bits/stdc++.h>
#define maxn 105
using namespace std;
int n;
int a[maxn],b[maxn];
map< vector<int>,int > mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		b[i]=a[i]&32767;
		a[i]>>=15;
	}
	for(int S=0;S<32768;++S)
	{
		vector<int> A;
		A.clear();
		for(int i=1;i<=n;++i)A.push_back(__builtin_popcount(S^a[i]));
		if(!mp.count(A))mp[A]=S;
	}
	for(int S=0;S<32768;++S)
	{
		vector<int> B;
		B.clear();
		for(int i=1;i<=n;++i)B.push_back(-(__builtin_popcount(S^b[i])));
		for(int j=0;j<=30;++j)
		{
			for(int i=0;i<n;++i)B[i]++;
			if(mp.count(B))
			{
				int x=S|(mp[B]<<15);
				cout<<x<<endl;
				return 0;
			}
		}
	}
	puts("-1");
}