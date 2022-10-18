#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;
const int MaxNum = 10000000;
const int MaxNPrime = MaxNum / 4;

vector<int> prime;
bool isPrime[MaxNum + 1];
inline void calcPrime()
{
	fill(isPrime + 1, isPrime + MaxNum + 1, true);
	isPrime[1] = false;
	for (int i = 2; i <= MaxNum; i++)
	{
		if (isPrime[i])
			prime.push_back(i);
		for (vector<int>::iterator j = prime.begin(); j != prime.end() && i * (*j) <= MaxNum; j++)
		{
			if (!isPrime[i * (*j)])
				break;
			isPrime[i * (*j)] = false;
		}
	}
}

int main()
{
	calcPrime();

	static int bucket[MaxNum + 1];
	int n, m;
	static vector<int> a[MaxN], b[MaxM];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);

		for (vector<int>::iterator j = prime.begin(); j != prime.end() && *j * *j <= num; j++)
			while (num % *j == 0)
			{
				bucket[*j]++;
				a[i].push_back(*j);
				num /= *j;
			}
		if (num != 1)
		{
			bucket[num]++;
			a[i].push_back(num);
		}
	}
	for (int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);

		for (vector<int>::iterator j = prime.begin(); j != prime.end() && *j * *j <= num; j++)
			while (num % *j == 0)
			{
				bucket[*j]--;
				b[i].push_back(*j);
				num /= *j;
			}
		if (num != 1)
		{
			bucket[num]--;
			b[i].push_back(num);
		}
	}

	vector<int> aout, bout;

	for (int i = 0; i < n; i++)
	{
		int t = 1;
		for (vector<int>::iterator j = a[i].begin(); j != a[i].end(); j++)
			if (bucket[*j] > 0)
			{
				bucket[*j]--;
				t *= *j;
			}
		aout.push_back(t);
	}
	for (int i = 0; i < m; i++)
	{
		int t = 1;
		for (vector<int>::iterator j = b[i].begin(); j != b[i].end(); j++)
			if (bucket[*j] < 0)
			{
				bucket[*j]++;
				t *= *j;
			}
		bout.push_back(t);
	}

	cout << aout.size() << ' ' << bout.size() << endl;
	for (vector<int>::iterator i = aout.begin(); i != aout.end(); i++)
		printf("%d ", *i);
	cout << endl;
	for (vector<int>::iterator i = bout.begin(); i != bout.end(); i++)
		printf("%d ", *i);
	cout << endl;

	return 0;
}