#include <iostream>

int a[5050];

int qry(int a, int b)
{
	int ans;
	std::cout << "? " << a << ' ' << b << std::endl;
	std::cin >> ans;
	return ans;
}

int c[3];

int main()
{
	int n;
	std::cin >> n;
	c[0]=qry(1,2);
	c[1]=qry(2,n);
	c[2]=qry(1,n);
	a[2]=(c[0]+c[1]-c[2])/2;
	a[n]=(c[2]+c[1]-c[0])/2;
	a[1]=(c[0]+c[2]-c[1])/2;
	for(int i=3;i<n;i++)
	{
		a[i]=qry(i,i-1);
		a[i]-=a[i-1];
		
	}
	std::cout << "! " << a[1];
	for(int i=2;i<=n;i++)
		std::cout << ' ' << a[i];
	std::cout << std::endl;
}