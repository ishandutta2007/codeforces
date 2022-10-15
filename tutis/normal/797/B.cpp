#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int64_t N;
	cin >> N;
	int A[N];
	int suma = 0;
	multiset<int>nel;
	multiset<int>lyg;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		suma += A[i];
		if ((A[i] + 10000) % 2 == 0)
			lyg.insert(A[i]);
		else
			nel.insert(A[i]);
	}
	if ((suma + 10000) % 2 == 0)
	{
		suma -= *nel.begin();
		nel.erase(nel.begin());
	}
	while (!lyg.empty() and * lyg.begin() <= 0)
	{
		suma -= *lyg.begin();
		lyg.erase(lyg.begin());
	}
	while (nel.size() >= 2 and (*nel.begin() + * (++nel.begin())) <= 0)
	{
		suma -= (*nel.begin() + * (++nel.begin()));
		nel.erase(nel.begin());
		nel.erase(nel.begin());
	}
	cout << suma;
	return 0;
}