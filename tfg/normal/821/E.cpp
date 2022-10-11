#include <iostream>
#include <vector>

typedef long long ll;

const ll MOD = ll(1e9) + 7;

struct Mat
{
	Mat(int n, int m)
	{
		a = std::vector<std::vector<ll> > (n, std::vector<ll>(m, 0));
	}

	Mat mul(Mat lul)
	{
		int n, m;
		n = a.size(), m = lul.a[0].size();
		//std::cout << "multiplying (" << a.size() << ", " << a[0].size() << ") by (" << lul.a.size() << ", " << lul.a[0].size() << ")\n";
		Mat ans(n, m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				for(int k = 0; k < lul.a.size(); k++)
				{
					//std::cout << "(" << i << ", " << j << ") += (" << i << ", " << k << ") * (" << k << ", " << j << ")\n";
					ans.a[i][j] += a[i][k] * lul.a[k][j];
					ans.a[i][j] %= MOD;
				}
			}
		}
		return ans;
	}

	void print()
	{
		for(int i = 0; i < a.size(); i++)
		{
			for(int j = 0; j < a[i].size(); j++)
			{
				std::cout << a[i][j] << ' ';
			}
			std::cout << '\n';
		}
	}

	std::vector<std::vector<ll> > a;
};

Mat fexp(Mat a, ll e)
{
	int n = a.a.size();
	Mat ans(n, n);
	for(int i = 0; i < n; i++)
		ans.a[i][i] = 1;
	//std::cout << "base:\n";
	//a.print();
	for(; e > 0; e /= 2)
	{
		if(e & 1)
		{
			ans = ans.mul(a);
			//std::cout << "new ans is:\n";
			//ans.print();
		}
		a = a.mul(a);
		//std::cout << "new base is:\n";
		//a.print();
	}
	//std::cout << "on fexp got:\n";
	//ans.print();
	return ans;
}

ll l[110], r[110], lim[110];

int main()
{
	int n;
	ll k;
	std::cin >> n >> k;
	for(int i = 0; i < n; i++)
	{
		std::cin >> l[i] >> r[i] >> lim[i];
		r[i] = std::min(k, r[i]);
	}
	Mat ans(16, 1);
	ans.a[0][0] = 1;
	//std::cout << "at first\n";
	//ans.print();
	for(int i = 0; i < n; i++)
	{
		Mat wut(16, 16);
		for(int j = 0; j <= lim[i]; j++)
		{
			if(j - 1 >= 0)
				wut.a[j][j - 1]++;
			wut.a[j][j]++;
			if(j + 1 <= lim[i])
				wut.a[j][j + 1]++;
		}
		//std::cout << "\ntransition on " << i << ":\n";
		//wut.print();
		//std::cout << "\n\n";
		ans = fexp(wut, r[i] - l[i]).mul(ans);
		//std::cout << "new ans is:\n";
		//ans.print();
	}
	std::cout << ans.a[0][0] << '\n';
}