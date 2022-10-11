#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

int n, w, h;

struct dancer
{
	int type, start, pos, idx, to, from;

	void read(int idx)
	{
		this->idx = this->to = this->from = idx;
		std::cin >> type >> pos >> start;
		type -= 1;
	}

	bool collide(dancer b)
	{
		return this->influence() == b.influence();
	}

	int influence()
	{
		return pos - start;
	}

	void print()
	{
		if(type == 0)
		{
			std::cout << this->pos << ' ' << h << '\n';
		}
		else
		{
			std::cout << w << ' ' << this->pos << '\n';
		}
	}
};

bool byPos(dancer a, dancer b)
{
	return a.pos < b.pos;
}

bool byInfluence(dancer a, dancer b)
{
	return a.influence() < b.influence() || (a.influence() == b.influence() && a.start < b.start);
}

const int ms = 100100;

std::vector<dancer> dnc[2], init;
dancer original[ms];
int ans[ms];

int main()
{
	std::cin >> n >> w >> h;
	for(int i = 0; i < n; i++)
	{
		dancer cur;
		cur.read(i);
		dnc[cur.type].push_back(cur);
		original[i] = cur;
		init.push_back(cur);
	}
	for(int i = 0; i < 2; i++)
		std::sort(dnc[i].begin(), dnc[i].end(), byInfluence);
	int ll = 0;
	for(int l = 0, r = 0; l < dnc[0].size(); l = r)
	{
		while(ll < dnc[1].size() && dnc[0][l].influence() > dnc[1][ll].influence())
			ll++;
		int rr = ll;
		while(rr < dnc[1].size() && dnc[0][l].influence() == dnc[1][rr].influence())
			rr++;
		while(r < dnc[0].size() && dnc[0][r].influence() == dnc[0][l].influence())
			r++;
		//std::cout << "on influence " << dnc[0][l].influence() << ", (" << l << ", " << r << "), (" << ll << ", " << rr << ")\n";
		
		if(rr == ll)
			continue;
		//std::cout << "on influence " << dnc[0][l].influence() << ", (" << l << ", " << r << "), (" << ll << ", " << rr << ")\n";
		for(int i = l; i < r; i++)
		{
			int up = r - i - 1;
			if(up <= rr - ll - 1)
			{
				dnc[0][i].to = dnc[1][ll + up].idx;
			}
			else
			{
				dnc[0][i].to = dnc[0][r - (up - (rr - ll - 1))].idx;
			}
		}
		for(int i = ll; i < rr; i++)
		{
			int up = rr - i - 1;
			if(up <= r - l - 1)
			{
				dnc[1][i].to = dnc[0][l + up].idx;
			}
			else
			{
				dnc[1][i].to = dnc[1][rr - (up - (r - l - 1))].idx;
			}
		}
		ll = rr;
	}
	for(auto a : dnc[1])
		ans[a.idx] = a.to;
	for(auto a : dnc[0])
		ans[a.idx] = a.to;
	for(int i = 0; i < n; i++)
		original[ans[i]].print();
}