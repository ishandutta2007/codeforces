#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

constexpr int SIZE = 131072;
double stree1[SIZE*2+1], stree2[SIZE*2+1];

void update_internal(int pos)
{
	int child1 = pos << 1;
	int child2 = child1 + 1;

	double a = stree1[child1];
	double b = stree2[child1];
	double c = stree1[child2];
	double d = stree2[child2];

	stree1[pos] = a*c/(1-(1-b)*(1-c));
	stree2[pos] = b*d/(1-(1-b)*(1-c));
}

void update(int pos, int a, int b)
{
	pos += SIZE;
	stree1[pos] = (double)a/b;
	stree2[pos] = (double)(b-a)/b;

	for (pos >>= 1; pos >= 1; pos >>= 1)
	{
		update_internal(pos);
	}
}

double query(int l, int r)
{
	vector<pair<double, double>> vt1, vt2;
	l += SIZE; r += SIZE;
	while (l <= r)
	{
		if (l & 1)
		{
			vt1.emplace_back(stree1[l], stree2[l]);
			l++;
		}
		if ((r & 1) == 0)
		{
			vt2.emplace_back(stree1[r], stree2[r]);
			r--;
		}
		l >>= 1; r >>= 1;
	}

	vt1.insert(vt1.end(),vt2.rbegin(),vt2.rend());

	while (vt1.size()>=2)
	{
		auto right = vt1.back(); vt1.pop_back();
		auto left = vt1.back(); vt1.pop_back();
		double a=left.first; double b=left.second;
		double c=right.first; double d=right.second;
		vt1.emplace_back(a*c/(1-(1-b)*(1-c)), b*d/(1-(1-b)*(1-c)));
	}
	return vt1[0].first;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i = 0; i < n; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		stree1[i+SIZE] = (double)a/b;
		stree2[i+SIZE] = (double)(b-a)/b;
	}

	for (int i = n; i < SIZE; i++)
	{
		stree1[i] = 1; stree2[i] = 0;
	}

	for (int i = SIZE - 1; i >= 1; i--)
		update_internal(i);

	for (int i = 0; i < q; i++)
	{
		int type;
		scanf("%d",&type);
		if (type == 1)
		{
			int idx,a,b;
			scanf("%d%d%d",&idx,&a,&b);
			idx--;
			update(idx,a,b);
		}
		else
		{
			int l,r;
			scanf("%d%d",&l,&r);
			l--; r--;
			printf("%.9f\n", query(l, r));
		}
	}
}