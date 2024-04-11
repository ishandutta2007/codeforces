#include <iostream>
#include <vector>
#include <algorithm>

long long int n;

bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
}

int largest_div(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return x/i;
	}
	return 1;
}

int memo[400];
bool visit[400];

int solve(int n)
{
	//std::cout << "on " << n << '\n';
	//int lixo;std::cin >> lixo;
	if(n<400)
	{
		if(visit[n]) return memo[n];
		visit[n]=true;
	}
	if(prime(n))
	{
		if(n<400) memo[n]=1;
		return 1;
	}
	int num=n-2;
	int ans=largest_div(n);
	while(1)
	{
		int result=largest_div(num);
		//std::cout << "trying " << num << " on " << n << ", result " << result << '\n';
		ans=std::min(ans,result+solve(n-num));
		if(result==1)
			break;
		num--;
	}
	if(n<400)
		memo[n]=ans;
	return ans;
}

int main()
{
	std::cin >> n;
	if(n%2==0 && n!=2)
		std::cout << "2\n";
	else if(prime(n))
		std::cout << "1\n";
	else if(prime(n-2))
		std::cout << "2\n";
	else
		std::cout << "3\n";
}