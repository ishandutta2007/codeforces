#include <cstdio>
#include <iostream>


int a[1000100];
int dude[1000];

int main()
{
	int n;
	std::cin >> n;
	int cur=1;
	int sum=0;
	for(int i=1;i<=60;i++)
	{
		while(sum+cur<=i)
		{
			sum+=cur;
			cur++;
		}
		dude[i]=cur-1;
	}
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		temp=dude[temp];
		a[i]=temp;
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans^=a[i];
	if(!ans)
		std::cout << "YES\n";
	else
		std::cout << "NO\n";
}