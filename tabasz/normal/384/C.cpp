#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long

int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	LL li=0, w=0;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		int a;
		scanf("%d", &a);
		if(a==1) li++;
		else w+=li;
	}
	cout<< w << "\n";
	return 0;
}