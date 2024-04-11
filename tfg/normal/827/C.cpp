#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

int dec[256];
std::string str;
char buffer[15];

class BIT
{
public:
	BIT()
	{
		BIT(1);
	}

	BIT(int n)
	{
		bit = std::vector<int>(n + 2, 0);
	}

	int qry(int x)
	{
		int ans = 0;
		for(; x > 0; x -= x & -x)
			ans += bit[x];
		return ans;
	}

	int qry(int l, int r)
	{
		return qry(r) - qry(l - 1);
	}

	void upd(int x, int v)
	{
		for(; x < bit.size(); x += x & -x)
			bit[x] += v;
	}

private:
	std::vector<int> bit;
};

BIT fw[4][11][11];

int main()
{
	dec['A'] = 0;
	dec['T'] = 1;
	dec['G'] = 2;
	dec['C'] = 3;
	std::cin >> str;
	int n = str.size();

	for(int i = 1; i <= 10; i++)
	{
		int size = (n + i - 1) / i;
		for(int j = 0; j < i; j++)
		{
			for(int k = 0; k < 4; k++)
			{
				fw[k][i][j] = BIT(size);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 1; j <= 10; j++)
		{
			fw[dec[str[i]]][j][i % j].upd(i / j + 1, 1);
		}
	}
	int q;
	std::cin >> q;
	while(q--)
	{
		int type;
		scanf("%i", &type);
		if(type == 1)
		{
			int x;
			char c;
			scanf("%i %c", &x, &c);
			x--;
			for(int i = 1; i <= 10; i++)
			{
				fw[dec[str[x]]][i][x % i].upd(x / i + 1, -1);
			}
			str[x] = c;
			for(int i = 1; i <= 10; i++)
			{
				fw[dec[str[x]]][i][x % i].upd(x / i + 1, 1);
			}
		}
		else
		{
			int l, r;
			scanf("%i %i %s", &l, &r, buffer);
			int size = 0;
			while(buffer[size] != 0)
				size++;
			l--;
			r--;
			if(r - l <= 30)
			{
				int ans = 0;
				for(int i = 0; i + l <= r; i++)
				{
					if(str[l + i] == buffer[i % size])
						ans++;
				}
				printf("%i\n", ans);
			}
			else
			{
				int ans = 0;
				for(int i = 0; i < size; i++)
				{
					int ll = (l + i) / size;
					int rr = r / size + 2;

					while(rr * size + (l + i) % size > r)
						rr--;
					int got = fw[dec[buffer[i]]][size][(l + i) % size].qry(ll + 1, rr + 1);
					//std::cout << "on pos " << i << ", making qry on fw[" << dec[buffer[i]] << "][" << size << "][" << (l + i) % size << "], (" << ll << ", " << rr << ") got " << got << "\n";
					ans += got;
				}
				printf("%i\n", ans);
			}
			for(int i = 0; i < size; i++)
				buffer[i] = 0;
		}
	}
}