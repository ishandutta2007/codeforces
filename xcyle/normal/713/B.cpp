#include <iostream>
#include <cstdio>
using namespace std;
int n, a[4], c[4];
int find(int *b, int pos)
{
	int l = 1, r = n, mid;
	if(pos <= 1) r = b[pos + 2];
	while(l < r)
	{
		mid = (l + r + (pos <= 1 ? 1 : 0)) >> 1;
		b[pos] = mid;
		cout<<"?"<<" "<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
		fflush(stdout);
		int num = 0;
		scanf("%d", &num);
		if(pos == 0 || pos == 1)
		{
			if(num == 0) r = mid - 1;
			else l = mid;
		}
		else
		{
			if(num == 0) l = mid + 1;
			else r = mid;
		}
	}
	b[pos] = l;
}
int find2(int *b, int pos)
{
	int l = 1, r = n, mid;
	if(pos <= 1) r = b[pos + 2];
	while(l < r)
	{
		mid = (l + r + (pos <= 1 ? 1 : 0)) >> 1;
		b[pos] = mid;
		cout<<"?"<<" "<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
		fflush(stdout);
		int num = 0;
		scanf("%d", &num);
		if(b[0] <= a[0] && a[2] <= b[2] && b[1] <= a[1] && a[3] <= b[3]) num--;
		if(pos == 0 || pos == 1)
		{
			if(num == 0) r = mid - 1;
			else l = mid;
		}
		else
		{
			if(num == 0) l = mid + 1;
			else r = mid;
		}
	}
	b[pos] = l;
}
int main()
{
	cin>>n;
	a[0] = 1;
	a[1] = 1;
	a[2] = n;
	a[3] = n;
	find(a, 3);
	find(a, 2);
	find(a, 1);
	find(a, 0);
	c[0] = 1;
	c[1] = 1;
	c[2] = n;
	c[3] = n;
	find2(c, 3);
	find2(c, 2);
	find2(c, 1);
	find2(c, 0);
	cout<<"! ";
	for (int i = 0; i <= 3; i++) cout<<a[i]<<" ";
	for (int i = 0; i <= 3; i++) cout<<c[i]<<" "; 
	fflush(stdout);
	return 0;
}