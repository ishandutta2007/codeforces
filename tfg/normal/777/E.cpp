#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

typedef std::pair<int, int> ii;
typedef std::pair<ii, int> i3;

bool cmp(i3 a, i3 b)
{
	if(a.first.first>b.first.first)
		return true;
	else if(a.first.first==b.first.first && a.first.second>b.first.second)
		return true;
	return false;
}

const int ms=100100;

i3 disc[ms];
int lul[ms];



typedef long long int s_t;

struct i_t
{
	i_t(){valid=false;}

	i_t(s_t a) //init
	{
		valid=true;
		num=a;
	}

	i_t(i_t a, i_t b)
	{
		if(!a.valid)
			*this=b;
		else if(!b.valid)
			*this=a;
		else
		{
			valid=true;
			//merge
			num=std::max(a.num,b.num);
		}
	}
	//atributos

	bool valid;
	long long int num;
};

class Segment_Tree
{
public:
	Segment_Tree(std::vector<s_t> &_a)
	{
		a.swap(_a);
		n=a.size();
		i_t temp;
		st.assign(4*n, temp);
		build(0, 0, n-1);
	}

	i_t qry(int i, int j){return qry(0, 0, n-1, i, j);}
	void update(int pos, s_t val){update(0, 0, n-1, pos, val);}
private:
	int left(int p){return (p<<1)+1;}
	int right(int p){return (p<<1)+2;}
	std::vector<s_t> a;
	std::vector<i_t> st;
	int n;

	void build(int ind, int l, int r)
	{
		if(l==r)
		{
			st[ind] = i_t(a[l]);
			return;
		}
		build(left(ind), l, (l+r)/2);
		build(right(ind), (l+r)/2+1, r);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	void update(int ind, int l, int r, int pos, s_t &val)
	{
		if(l>pos || r<pos)
			return;

		if(l==r)
		{
			a[pos] = std::max(a[pos], val);
			st[ind] = i_t(a[pos]);
			return;
		}

		update(left(ind), l, (l+r)/2, pos, val);
		update(right(ind), (l+r)/2+1, r, pos, val);
		st[ind] = i_t(st[left(ind)], st[right(ind)]);
	}

	i_t qry(int ind, int l, int r, int i, int j)
	{
		if(r<i || l>j)
			return i_t();

		else if(l>=i && r<=j)
			return st[ind];

		return i_t(qry(left(ind), l, (l+r)/2, i, j), qry(right(ind), (l+r)/2+1, r, i, j));
	}
};

int main()
{
	int n;
	std::cin >> n;
	std::vector<long long int> wtf;
	for(int i=0;i<n;i++)
	{
		int inner, outer, height;
		scanf("%i %i %i",&inner,&outer,&height);
		lul[i]=inner;
		disc[i]=i3(ii(outer,inner),height);
		wtf.push_back(0);
	}
	std::sort(disc,disc+n,cmp);
	std::sort(lul,lul+n);
	Segment_Tree seg_tree(wtf);
	long long int ans=0;
	for(int i=0;i<n;i++)
	{
		int inner, outer, height;
		inner=disc[i].first.second;
		outer=disc[i].first.first;
		height=disc[i].second;
		//std::cout << "(" << outer << ", " << inner << ", " << height << ")\n";
		int cur_ind=int(std::lower_bound(lul,lul+n,outer)-lul);
		int out_ind=int(std::lower_bound(lul,lul+n,inner)-lul);
		cur_ind=std::min(cur_ind, n-1);
		if(lul[cur_ind]>=outer)
			cur_ind--;
		//std::cout << "outer bound is " << cur_ind << '\n';
		//std::cout << "inner bound is " << out_ind << '\n';
		long long int cur_ans=height;
		if(cur_ind>0)
			cur_ans+=seg_tree.qry(0, cur_ind).num;
		
		seg_tree.update(out_ind, cur_ans);
		ans=std::max(ans, cur_ans);
	}
	std::cout << ans << '\n';
}