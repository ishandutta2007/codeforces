#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> st;
	int n;
	scanf("%d", &n);
	int z = n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		st.insert(tmp);
		while (st.count(z) == 1)
		{
			printf("%d ", z);
			st.erase(z);
			--z;
		}
		printf("\n");
	}
}