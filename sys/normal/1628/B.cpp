#include <bits/stdc++.h>
using namespace std;

int T, n;
set <string> Se2, Se3;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		bool flag = false;
		Se2.clear(), Se3.clear();
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			string str;
			cin >> str;
			if (str.size() == 1) flag = true;
			if (str.size() == 2 && str[0] == str[1]) flag = true;
			if (str.size() == 3 && str[0] == str[2]) flag = true;
			string tmp = "";
			for (int j = str.size() - 1; j >= 0; j--)
				tmp += str[j];
			if (str.size() == 2)
			{
				if (Se2.find(tmp) != Se2.end()) flag = true;
				if (Se3.find(tmp) != Se3.end()) flag = true;
				Se2.insert(str);
			}
			if (str.size() == 3)
			{
				if (Se3.find(tmp) != Se3.end()) flag = true;
				if (Se2.find(tmp.substr(0, 2)) != Se2.end()) flag = true;
				Se3.insert(str);
				Se3.insert(str.substr(0, 2));
			}
		}
		puts(flag ? "YES" : "NO");
	}
	return 0;
}