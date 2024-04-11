#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[30][30] = {0};
	string s;
	cin >> s;
	for(int i = 0; i < n - 1;i++)
	{
		a[(int)(s[i]-'A')][(int)(s[i+1]-'A')]++;
	}
	int maxa = 0;
	char a1, a2;
	for(int i = 0;i < 30; i++)
	{
		for(int j = 0;j < 30; j++)
		{
			if(a[i][j] > maxa)
			{
				maxa = a[i][j];
				a1 = (char)('A'+i);
				a2 = (char)('A'+j);
			}
		}
	}
	cout << a1 << a2;
}