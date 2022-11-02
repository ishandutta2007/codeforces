#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
#define PB push_back
#define LL long long
vector<int > V;

int main()
{
	ios_base::sync_with_stdio(0);
	int n, m, x=0;
	LL w=0;
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		V.PB(b);
	}
	sort(V.begin(), V.end());
	if(n==1) x=1;
	if(n>1 && n<4) x=2;
	if(n>3 && n<8) x=3;
	if(n>=8)
	{
		bool b=1;
		x=4;
		while(b)
		{
			int a=x*(x/2);
			if(x%2==1) a++;
			if(a>n) b=0;
			else x++;
		}
		x--;
	}
	//printf("%d\n", x);
	for(int i=m-1; i>=max(m-x, 0); i--) w+=(LL)V[i];
	cout<< w << "\n";
	return 0;
}