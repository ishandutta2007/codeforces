#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>


int n, k;
int c[2];
char out[2];

std::string ans;

int get_min(int N, int K)
{
	return N/(K+1);
}

int get_max(int N, int K)
{
	return N - get_min(N, K);
}

int main()
{
	std::cin >> n >> k >> c[0] >> c[1];
	int max_needed=get_max(n, k);
	if(c[0]>max_needed || c[1]>max_needed)
	{
		std::cout << "NO\n";
		return 0;
	}

	out[0]='G';
	out[1]='B';

	if(c[1]>c[0])
	{
		std::swap(out[0], out[1]);
		std::swap(c[0], c[1]);
	}

	int on=0;

	while(on!=n)
	{
		int size=std::min(k+1, n-on);
		if(size==c[0]+c[1])
		{
			for(int i=0;i<c[0];i++)
				printf("%c",out[0]);
			for(int i=0;i<c[1];i++)
				printf("%c",out[1]);
			break;
		}

		//int use_max=std::min(c[0], k);
		int use_max=-get_max(n-on-(k+1),k)+c[0];
		//std::cout << "currently has " << c[0] << ", next max is " << get_max(n-on-(k+1),k) << ", got " << use_max << '\n';
		use_max=std::min(use_max, k);
		use_max=std::max(use_max, 1);
		int use_min=k+1-use_max;
		use_min=std::min(-get_min(n-on-(k+1),k)+c[1], use_min);
		use_min=std::min(use_min, k);
		use_min=std::max(use_min, 1);
		use_max=k+1-use_min;

		for(int i=0;i<use_max;i++)
		{
			c[0]--;
			printf("%c",out[0]);
		}

		for(int i=0;i<use_min;i++)
		{
			c[1]--;
			printf("%c",out[1]);
		}



		on+=k+1;
	}

	std::cout << '\n';


}