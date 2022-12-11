#include "bits/stdc++.h"
using namespace std;

int dat[50005];
set<int> st;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &dat[i]);
		st.insert(dat[i]);
	}

	for (;;)
	{
		int target = *st.rbegin();
		int nv = target;
		for (nv >>= 1; nv >= 1 && st.count(nv); nv >>= 1);
		if (nv == 0) break;
		st.erase(target);
		st.insert(nv);
	}

	for (int t : st) printf("%d ", t);
}