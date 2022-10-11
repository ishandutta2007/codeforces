#include <iostream>
#include <cstdio>

const int ms = 101000;
const int bs = 800;

int freq[ms / bs + 2][ms];
int val[ms], start[ms / bs + 2];

int getPos(int pos)
{
	int bucket = pos / bs;
	return bucket * bs + (start[bucket] + pos) % bs;
}

int get(int pos)
{
	return val[getPos(pos)];
}

void update(int l, int r)
{
	int lb = l / bs, rb = r / bs;
	if(lb == rb)
	{
		int last = get(r);
		for(int i = r; i > l; i--)
			val[getPos(i)] = get(i - 1);
		val[getPos(l)] = last;
	}
	else if(lb + 1 == rb)
	{
		int middle = get(rb * bs - 1);
		int last = get(r);
		freq[lb][middle]--;
		freq[rb][middle]++;
		freq[lb][last]++;
		freq[rb][last]--;
		for(int i = r; i > l; i--)
			val[getPos(i)] = get(i - 1);
		val[getPos(l)] = last;
	}
	else
	{
		int last = get(r);
		freq[rb][last]--;
		freq[rb][get(rb * bs - 1)]++;
		for(int i = r; i >= bs * rb; i--)
			val[getPos(i)] = get(i - 1);
		for(int i = rb - 1; i > lb; i--)
		{
			freq[i][get(i * bs + bs - 1)]--;
			freq[i][get(i * bs - 1)]++;
			val[getPos(i * bs + bs - 1)] = get(i * bs - 1);
			start[i] = (start[i] + bs - 1) % bs;
		}
		freq[lb][get(lb * bs + bs - 1)]--;
		freq[lb][last]++;
		for(int i = bs * lb + bs - 1; i > l; i--)
			val[getPos(i)] = get(i - 1);
		val[getPos(l)] = last;
	}
}

int qry(int l, int r, int k)
{
	int lb = l / bs, rb = r / bs;
	int ans = 0;
	for(int i = lb + 1; i < rb; i++)
		ans += freq[i][k];
	for(int i = l; i <= std::min(lb * bs + bs - 1, r); i++)
		ans += get(i) == k ? 1 : 0;
	if(lb == rb)
		return ans;
	for(int i = rb * bs; i <= r; i++)
		ans += get(i) == k ? 1 : 0;
	return ans;
}


int main()
{
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		//std::cin >> val[i];
		scanf("%i", val + i);
		freq[i / bs][val[i]]++;
	}
	int q;
	std::cin >> q;
	int lastans = 0;
	while(q--)
	{
		int t, l, r;
		//std::cin >> t >> l >> r;
		scanf("%i %i %i", &t, &l, &r);
		l = (l + lastans + n - 1) % n;
		r = (r + lastans + n - 1) % n;
		if(l > r)
			std::swap(l, r);
		//std::cout << "qry (" << t << ", " << l << ", " << r << ")\n";
		if(t == 1)
		{
			update(l, r);
			//for(int i = 0; i < n; i++)
			//	std::cout << get(i) << ' ';
			//std::cout << '\n';
		}
		else
		{
			int k;
			//std::cin >> k;
			scanf("%i", &k);
			k = (k + lastans + n - 1) % n + 1;
			//std::cout << "k is " << k << '\n';
			int ans = qry(l, r, k);
			lastans = ans;
			std::cout << ans << '\n';
		}
	}
}