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

int n, m;
int T[100005];
int R[300005];
map<int, LL> M;

int gcd(int a, int b)
{
	if(a<b) swap(a, b);
	if(b==0) return a;
	return gcd(b, a%b);
}

void jebaj(int p, int k)
{
	map<int, int>::iterator it;
	if(p==k)
	{
		M[T[p]]++;
		return;
	}
	int mid=(p+k)/2;
	jebaj(p, mid);
	jebaj(mid+1, k);
	vector<pair<int, int> > V1, V2;
	int x=T[mid], y=T[mid+1], l1=1, l2=1;
	for(int i=mid-1; i>=p; i--)
	{
		int gc=gcd(x, T[i]);
		if(gc!=x)
		{
			V1.PB(MP(x, l1));
			l1=0;
			x=gc;
		}
		l1++;
	}
	if(l1>0) V1.PB(MP(x, l1));
	for(int i=mid+2; i<=k; i++)
	{
		int gc=gcd(y, T[i]);
		if(gc!=y)
		{
			V2.PB(MP(y, l2));
			l2=0;
			y=gc;
		}
		l2++;
	}
	if(l2>0) V2.PB(MP(y, l2));
	for(int i=0; i<(int)V1.size(); i++)
	{
		for(int j=0; j<(int)V2.size(); j++)
		{
			int qwe=gcd(V1[i].F, V2[j].F);
			/*it=M.find(qwe);
			if(it!=M.end()) R[it->S]+=(LL)V1[i].S*(LL)V2[j].S;*/
			M[qwe]+=(LL)V1[i].S*(LL)V2[j].S;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<n; i++) cin>> T[i];
	cin>> m;
	for(int i=0; i<m; i++)
	{
		int a;
		cin>> a;
		R[i]=a;
	}
	jebaj(0, n-1);
	for(int i=0; i<m; i++) cout<< M[R[i]] << '\n';
	return 0;
}