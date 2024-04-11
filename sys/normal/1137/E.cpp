#include <bits/stdc++.h>
using namespace std;

const int Maxn = 600005;
int n, m, top;
long long End, pos, shift;
pair <long long, long long> sta[Maxn];
double slope(pair <long long, long long> x, pair <long long, long long> y)
{
	return (x.second - y.second) / (double) (x.first - y.first);
}
int main()
{
	scanf("%d%d", &n, &m);
	sta[++top] = make_pair(0, 0), End = n;
	while (m--)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int k;
			scanf("%d", &k);
			top = shift = pos = 0;
			sta[++top] = make_pair(0, 0), End += k;
		}
		else if (opt == 2)
		{
			int k;
			scanf("%d", &k);
			while (top > 1 && slope(sta[top - 1], sta[top]) >= slope(sta[top], make_pair(End, -shift - pos * End))) top--;
			sta[++top] = make_pair(End, -shift - pos * End), End += k;
		}
		else
		{
			int b, s;
			scanf("%d%d", &b, &s);
			shift += b;
			pos += s;
		}
		while (top > 1 && sta[top - 1].second - sta[top].second <= pos * (sta[top].first - sta[top - 1].first)) top--;
		printf("%lld %lld\n", sta[top].first + 1, shift + sta[top].second + sta[top].first * pos);
	}
	return 0;
}