#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int> 
#define PLL pair<LL, LL> 

int n, res;
vector<pair<string, int> > V[2];
vector<PII> R;

vector<int> go(int p1, int k1, int p2, int k2, int d)
{
	//printf("res=%d\n", res);
	//printf("%d %d %d %d %d\n", p1, k1, p2, k2, d);
	while(p1<=k1 && p2<=k2 && (int)V[0][p1].F.size()==d && (int)V[1][p2].F.size()==d)
	{
		res+=d;
		R.PB(MP(V[0][p1].S, V[1][p2].S));
		p1++;
		p2++;
	}
	vector<int> X;
	if(p1>k1 && p2>k2)
		return X;
	if(p1>k1)
	{
		vector<int> W;
		for(int i=p2; i<=k2; i++)
		{
			W.PB(-(V[1][i].S));
		//	printf("lol %d\n",-(V[1][i].S));
		}
		return W;
	}
	if(p2>k2)
	{
		vector<int> W;
		for(int i=p1; i<=k1; i++)
		{
			//printf("lol %d\n", V[0][i].S);
			W.PB(V[0][i].S);
		}
		return W;
	}
	if((int)V[0][p1].F.size()==d)
	{
		int qwe=p1;
		while(qwe<=k1 && (int)V[0][qwe].F.size()==d)
			qwe++;
		X=go(p1, qwe-1, p2, p2-1, d+1);
		p1=qwe;
	}
	if((int)V[1][p2].F.size()==d)
	{
		int qwe=p2;
		while(qwe<=k2 && (int)V[1][qwe].F.size()==d)
			qwe++;
		X=go(p1, p1-1, p2, qwe-1, d+1);
		p2=qwe;
	}
	for(int i=0; i<26; i++)
	{
		int ind1=p1;
		int ind2=p2;
		while(ind1<=k1 && (int)V[0][ind1].F[d]==(int)'a'+i)
			ind1++;
		while(ind2<=k2 && (int)V[1][ind2].F[d]==(int)'a'+i)
			ind2++;
		if(ind1!=p1 || ind2!=p2)
		{
			vector<int> Y=go(p1, ind1-1, p2, ind2-1, d+1);
			while(!Y.empty())
			{
				if(X.empty() || (LL)X[X.size()-1]*Y[Y.size()-1]>=0)
					X.PB(Y[Y.size()-1]);
				else
				{
					res+=d;
					if(X[X.size()-1]>0)
						R.PB(MP(X[X.size()-1], -Y[Y.size()-1]));
					else
						R.PB(MP(Y[Y.size()-1], -X[X.size()-1]));
					X.pop_back();
				}
				Y.pop_back();
			}
			p1=ind1;
			p2=ind2;
		}
	}
	return X;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin>> n;
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<n; j++)
		{
			string s;
			cin>> s;
			V[i].PB(MP(s, j+1));
		}
		sort(V[i].begin(), V[i].end());
	}
	//for(int i=0; i<n; i++)
	//	printf("%d %d\n", V[0][i].S, V[1][i].S);
	go(0, n-1, 0, n-1, 0);
	cout<< res << '\n';
	for(int i=0; i<n; i++)
		cout<< R[i].F << ' ' << R[i].S << '\n';
	return 0;
}