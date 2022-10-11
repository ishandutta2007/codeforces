#include <iostream>
#include <string>
#include <vector>

std::string str;
int freq[256];

std::vector<int> change_this;

char aux[]={'A','G','C','T'};

int main()
{
	int n;
	std::cin >> n >> str;
	bool valid=(n%4==0);
	for(int i=0;i<n;i++)
	{
		freq[str[i]]++;

		if(str[i]=='?')
			change_this.push_back(i);
		else if(freq[str[i]]>n/4)
		{
			valid=false;
			//std::cout << "not valid on " << i << " letter is " << str[i] << " freq is " << freq[str[i]] << '\n';
		}
	}
	if(valid)
	{
		int count=0;
		for(int i=0;i<4;i++)
		{
			for(int j=freq[aux[i]];j<n/4;j++)
			{
				freq[aux[i]]++;
				str[change_this[count++]]=aux[i];
				//std::cout << "j is " << j << '\n';
				//std::cout << "putting " << aux[i] << " on " << change_this[count-1] << '\n';
			}
		}
		std::cout << str << '\n';
	}
	else
		std::cout << "===\n";
}