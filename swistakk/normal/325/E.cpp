#include <iostream>
#define N 100005
using namespace std;
int n;
int prz(int a)
{
	return (a + n/2) % n;
}
int rep[N];
int find(int a)
{
	if (rep[a] == a)
	{
		return a;
	}
	else
	{
		rep[a] = find(rep[a]);
		return rep[a];
	}
}
void Union(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	else
	{
		//cout<<a<<" u "<<b<<endl;
		rep[b] = a;
	}
}
int nast[N];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	if (n % 2 == 1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		rep[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		//rep[i] = i;
		if (i < n / 2)
		{
			nast[i] = 2 * i % n;
		}
		else
		{
			nast[i] = (2 * i + 1) % n;
		}
		Union(i, nast[i]);
	}
	//cout<<find(5)<<endl;
	/* for (int i = 0; i < n; i++)
	{
		cout<<nast[i]<<" ";
	}
	cout<<endl; */
	for (int i = 0; i < n; i++)
	{
		int a = nast[i];
		int b = (nast[i] ^ 1);
		//cout<<find(i)<<" h "<<find(b)<<endl;
		if (find(i) != find(b))
		{
			nast[i] = b;
			nast[prz(i)] = a;
			//cout<<i<<" "<<b<<endl;
			//cout<<prz(i)<<" "<<a<<endl;
			Union(i, b);
		}
	}
	//cout<<find(5)<<endl;
	cout<<"0 ";
	for (int i = nast[0]; i != 0; )
	{
		cout<<i<<" ";
		i = nast[i];
	}
	cout<<"0"<<endl;
	return 0;
}