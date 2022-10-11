#include <iostream>
#include <set>
#include <utility>
#include <map>
#include <vector>
#include <cstdio>

typedef long long ll;
typedef std::pair<int, int> ii;

const int ms = 4e6;

int freq[ms];

int main()
{
	int n;
	std::cin >> n;
	
	std::vector<int> a;
	for(int i = 0; i < n; i++)
	{
		int temp;
		//std::cin >> temp;
		scanf("%i", &temp);
		a.push_back(temp);
	}
	for(int i = 0; i < n; i++)
		a[i] -= i + 1;
	int dec = 0;
	int inc = 0;
	ll cur_ans = 0;
	int shifts = 0;
	for(int i = 0; i < n; i++)
	{
		//std::cout << a[i] << ' ';
		if(a[i] > 0)
		{
			cur_ans += a[i];
			dec++;
			freq[a[i]]++;
		}
		else
		{
			cur_ans -= a[i];
			inc++;
		}
	}
	//std::cout << '\n';
	ll ans = cur_ans;
	int look = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		look++;
		cur_ans -= n - (a[i] + i + 1);
		cur_ans += a[i] + i;
		inc--;
		cur_ans -= dec;
		cur_ans += inc;
		dec++;
		freq[a[i] + i + look]++;
		inc += freq[look];
		dec -= freq[look];
		//std::cout << "answer on rotate " << n - i << " is " << cur_ans << "\n";
		if(cur_ans < ans)
		{
			ans = cur_ans;
			shifts = n - i;
		}
	}
	std::cout << ans << ' ' << shifts << '\n';
}