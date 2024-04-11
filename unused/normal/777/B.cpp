#include <bits/stdc++.h>
using namespace std;

string c1, c2;

int cnt1[10], cnt2[10];

int main()
{
	int n;
	cin >> n >> c1 >> c2;
	for (char ch : c1) cnt1[ch - '0']++;
	for (char ch : c2) cnt2[ch - '0']++;

	int remain = 0;
	int draw = 0;
	for (int i = 9; i >= 0; i--)
	{
		int diff = max(0, min(cnt1[i], cnt2[i] + remain));
		draw += diff;
		remain += cnt2[i] - diff;
	}
	printf("%d\n", n - draw);

	remain = 0; draw = 0;

	for (int i = 8; i >= 0; i--)
	{
		int diff = max(0, min(cnt1[i], cnt2[i + 1] + remain));
		draw += diff;
		remain += cnt2[i + 1] - diff;
	}
	printf("%d\n", draw);
}