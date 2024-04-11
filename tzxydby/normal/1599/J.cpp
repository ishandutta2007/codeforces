#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int ALL = (1<<16) + 5;

int num1[ALL];

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int b[MAXN]; 

int main(void)
{
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(b[i] == b[j])
			{
				swap(b[i], b[n]);
				printf("YES\n");
				printf("0 ");
				for(int k=1; k<n; ++k)
					printf("%d ",b[k]);
				return 0;
			}
	
	if(n == 2) return printf("NO"), 0;
	
	auto print3 = [&] (int x,int y,int z)
	{
		assert((b[x] + b[y] + b[z]) % 2 == 0);
		int p = b[x], q = b[y] - b[z];
		
		vector<int> a(n+1);
		a[y] = (p + q) / 2; a[z] = (p - q) / 2;
		a[x] = b[y] - a[y];
		printf("YES\n");
		for(int i=1; i<=n; ++i)
		{
			if(i != x && i != y && i != z) a[i] = b[i] - a[y];
			printf("%d ",a[i]);
		}
		exit(0);
	};
	
	vector<int> vec[2];
	for(int i=1; i<=n; ++i)
		vec[b[i] & 1].push_back(i);
	
	if(vec[0].size() >= 3) print3(vec[0][0], vec[0][1], vec[0][2]);
	if(vec[0].size() >= 1 && vec[1].size() >= 2)
		print3(vec[0][0], vec[1][0], vec[1][1]);
	
	if(n == 3) return printf("NO"), 0;
	assert(vec[0].size() == 0 && (int)vec[1].size() == n);
	
	auto half_search = [&] (int l,int r,auto func)
	{
		int len = (r - l + 1);
		auto get = [&] (int mask)
		{
			int cnt = num1[mask], sum = 0;
			for(int i=0; i<len; ++i)
				if(bdig(mask, i))
					sum += b[i + l];
			return make_pair(sum, cnt);
		};
		
		int all = (1<<len) - 1;
		for(int mask=0; mask<=all; ++mask)
			for(int mask2=mask; ; mask2=(mask2-1)&mask)
			{
				if(num1[mask ^ mask2] >= num1[mask2])
				{
					pii p = get(mask ^ mask2), q = get(mask2);
					p.first -= q.first; p.second -= q.second;
					func(p.first, p.second, mask ^ mask2, mask2);
				}
				if(!mask2) break;
			}
	};
	
	int m = min(n, 27);
	int half = m / 2;
	
	unordered_map<int,pii> mp[20];
	
	auto save_mp = [&] (int key1,int key2,int mask,int mask2)
	{
		mp[key2][key1] = make_pair(mask, mask2);
	};
	auto get_mp = [&] (int key1,int key2,int mask,int mask2)
	{
		if(mp[key2].find(key1) == mp[key2].end()) return;
		pii oth = mp[key2][key1];
		
		mask = (mask << half) | oth.second;
		mask2 = (mask2 << half) | oth.first;
		if(mask == 0 || mask2 == 0) return;
		
		vector<int> p,q;
		static bool vis[MAXN];
		for(int i=0; i<m; ++i)
		{
			if(bdig(mask, i)) p.push_back(b[i + 1]), vis[i + 1] = 1;
			if(bdig(mask2, i)) q.push_back(b[i + 1]), vis[i + 1] = 1;
		}
		assert((int)p.size() == (int)q.size());
		
		vector<int> res(1,0);
		for(int i=0; i<(int)p.size(); ++i)
		{
			res.push_back(p[i] - res.back());
			res.push_back(q[i] - res.back());
		}
		res.pop_back();
		
		for(int i=1; i<=n; ++i) if(!vis[i])
			res.push_back(b[i]);
		
		printf("YES\n");
		for(int x: res) printf("%d ",x);
		exit(0);
	};
	
	half_search(1, half, save_mp);
	half_search(half+1, m, get_mp);
	
	printf("NO");
	return 0;
}