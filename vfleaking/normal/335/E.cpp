#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 30000;
const int MaxH = 30;

int hm;

double getHProb(int h)
{
	if (h == hm)
		return pow(2, -hm);
	else
		return pow(2, -(h + 1));
}
double getLHProb(int h)
{
	if (h == hm + 1)
		return 1;
	else
		return 1 - pow(2, -h);
}
double getHProb(int h, int limH)
{
	return getHProb(h) / getLHProb(limH + 1);
}
double getLHProb(int h, int limH)
{
	return getLHProb(h) / getLHProb(limH + 1);
}

int main()
{
	string name;
	int n;
	cin >> name >> n >> hm;
	if (name == "Alice")
	{
		double e = n;
		double p = 1;
		double v = 1;
		for (int h = 1; h <= hm; h++)
		{
			p /= 2;
			v *= 2;

			double w = 1;
			for (int l = 1; l < n; l++, w *= 1 - p)
				e += (n - l) * p * w * (1 - (l - 1) / (v - 1)) / 2;
		}
		printf("%.10f\n", e);
	}
	else if (name == "Bob")
	{
		cout << n << endl;
	}

	return 0;
}