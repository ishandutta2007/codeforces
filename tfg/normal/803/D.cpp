#include <iostream>
#include <string>
#include <vector>

const int ms = int(1e6);

std::vector<std::string> str;
std::vector<std::vector<int> > lengths;

int k;

bool f(int x)
{
	int rows = 1;
	int space = x;
	for(int i = 0; i < lengths.size(); i++)
	{
		for(int j = 1; j < lengths[i].size(); j++)
		{
			if(lengths[i][j] - lengths[i][j - 1] > x)
				return false;
			space -= lengths[i][j] - lengths[i][j - 1];
			if(space < 0)
			{
				//std::cout << "on word " << str[i] << ", step " << j << " creating new line\n";
				rows++;
				//std::cout << "using " << (lengths[i][j] - lengths[i][j - 1]) << '\n';
				space = x - (lengths[i][j] - lengths[i][j - 1]);
			}
		}
	}
	//std::cout << "with " << x << " columns using " << rows << " rows\n";
	return rows <= k;
}

int main()
{
	std::cin >> k;
	std::string temp;
	int l = 1, r = ms;
	while(std::cin >> temp)
	{
		str.push_back(temp);
		lengths.push_back(std::vector<int> (1, 0));
		for(int i = 0; i < temp.size(); i++)
		{
			if(temp[i] == '-')
				lengths.back().push_back(i + 1);
		}
		lengths.back().push_back(temp.size() + 1);
		r = std::max(r, lengths.back().back());
	}
	lengths.back().back()--;
	r += r;
	while(l != r)
	{
		int mid = (l + r) / 2;
		if(f(mid))
			r = mid;
		else
			l = mid + 1;
	}
	std::cout << l << '\n';
}