#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int q[N],ql=1,qr;
set<int> st;
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	while(n--)
	{
		int x;
		scanf("%i",&x);
		if(!st.count(x))
		{
			st.insert(x);
			q[++qr]=x;
			if(qr-ql==k) st.erase(q[ql++]);
		}
	}
	printf("%i\n",qr-ql+1);
	for(int i=qr;i>=ql;i--) printf("%i ",q[i]);
	return 0;
}