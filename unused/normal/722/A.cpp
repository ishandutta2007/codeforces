#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a;char str[100];
	scanf("%d%s", &a, str);

	string ans;
	int diff = 99;
		for (int i = a == 12; i <= a - (a == 24); i++)
			for (int j = 0; j <= 59; j++)
		{
			char s[10];
			sprintf(s, "%02d:%02d", i, j);
			int dif = 0;
			for (int k = 0; k < 5; k++) dif += str[k] != s[k];
			if (dif < diff) diff = dif, ans = s;
		}
		puts(ans.c_str());
}