#include <stdio.h>
#include <set>
using namespace std;
set<int> st;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		st.insert(tmp);
		if (st.size() > 3)
		{
			printf("NO");
			return 0;
		}
	}

	if (st.size() <= 2) printf("YES");
	else
	{
		int a = *st.begin(), b = *++st.begin(), c = *st.rbegin();
		if (b - a == c - b) printf("YES");
		else printf("NO");
	}
}