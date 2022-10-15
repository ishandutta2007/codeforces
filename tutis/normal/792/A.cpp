#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	sort(A, A + N);
	int kiek = 0;
	int k = INT_MAX;
	for (int i = 0; i < N - 1; i++)
	{
		if (k>abs(A[i] - A[i + 1]))
		{
			k=abs(A[i] - A[i + 1]);
			kiek=0;
		}
		if (k==abs(A[i] - A[i + 1]))
		{
			kiek++;
		}
	}
	cout<<k<<" "<<kiek;
	return 0;
}