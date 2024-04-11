#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

int n;

int pos=0, neg=0;
char sig='+';

int main()
{
	std::string str;
	std::queue<char> q;
	while(std::cin >> str && str[0]!='=')
	{
		if(str[0]=='?')
		{
			if(sig=='+')
				pos++;
			else
				neg++;
			q.push(sig);
		}
		else
		{
			sig=str[0];
		}

	}
	std::cin >> n;
	int max_sum=n*pos-neg;
	int min_sum=pos-n*neg;
	//std::cout << '\n' << "max_sum = " << max_sum << ", min_sum = " << min_sum << '\n';

	if(!(n<=max_sum && n>=min_sum))
	{
		std::cout << "Impossible\n";
		return 0;
	}
	std::cout << "Possible\n";
	int count=0;
	while(!q.empty())
	{
		char op=q.front();
		int choice;
		q.pop();
		if(count!=0)
			std::cout << op << ' ';

		if(op=='+')
		{
			choice=std::max(1,2*n-max_sum);
			choice=std::min(choice,n);
			max_sum-=(n-choice);
			min_sum+=(choice-1);
		}
		else
		{
			choice=std::max(1,max_sum-n+1);
			choice=std::min(choice,n);
			max_sum-=(choice-1);
			min_sum+=(n-choice);
		}
		//std::cout << '\n' << "max_sum = " << max_sum << ", min_sum = " << min_sum << '\n';


		std::cout << choice << ' ';
		count++;
	}

	std::cout << "= " << n << '\n'; 
	//std::cout << '\n' << "max_sum = " << max_sum << ", min_sum = " << min_sum << '\n';

}