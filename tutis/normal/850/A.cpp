/***
3
0 0 1 2 0
0 0 9 2 0
0 0 5 9 0
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct vect
{
	ld x[5];
	void get()
	{
		for (int i = 0; i < 5; i++)
			cin >> x[i];
	}
};
vect operator-(vect a, vect b)
{
	vect c;
	for (int i = 0; i < 5; i++)
		c.x[i] = a.x[i] - b.x[i];
	return c;
}
vect operator^(vect a, vect b)
{
	return b - a;
}
ld operator*(vect a, vect b)
{
	ld ret = 0;
	for (int i = 0; i < 5; i++)
		ret += a.x[i] * b.x[i];
	return ret;
}
ld mod(vect a)
{
	return sqrtl(a * a);
}
#define PI 3.14159265358979323846264
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vect A[n];
	for (int i = 0; i < n; i++)
		A[i].get();
	vector<int>ats;
	for (int i = 0; i < n; i++)
	{
		bool good = true;
		for (int a = 0; a < n && good; a++)
		{
			if (a == i)
				continue;
			for (int b = 0; b < n && good; b++)
			{
				if (b == i || b == a)
					continue;
				vect x = A[i] ^ A[b];
				vect y = A[i] ^ A[a];
				if (acosl((x * y) / (mod(x) * mod(y))) + (1e-14) < (PI / 2.0))
				{
					good = false;
				}
			}
		}
		if (good)
			ats.push_back(i);
	}
	cout << ats.size() << "\n";
	for (int i : ats)
		cout << i + 1 << " ";
}