#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[100100];
long long m;

long long ans[100100];

int main()
{
	int N,X;
	cin>>N>>X;
	X--;
	for(int i=0;i<N;i++) cin>>a[i];
	m=1ll<<32;
	for(int i=0;i<N;i++) m=min(m,a[i]);
	for(int i=0;i<N;i++) a[i]-=m;
	int id=X;
	int cnt=0;
	for(;;)
	{
		if(a[id]==0) break;
		a[id]--;
		id--;
		cnt++;
		if(id==-1) id=N-1;
	}
	a[id]+=cnt;
	a[id]+=m*N;
	for(int i=0;i<N;i++)
	{
		cout<<a[i]<<(i==N-1?'\n':' ');
	}
	return 0;
}