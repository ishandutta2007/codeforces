#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>

class Small_Tree
{
public:
	Small_Tree(std::vector<int> &_a)
	{
		a=_a;
		n=a.size();
		st.assign(4*n, std::vector<int>(0));
		build(0, 0, n-1);
	}

	int qry(int i, int j, int k)
	{
		return qry(0, 0, n-1, i, j, k);
	}

private:
	int left(int p){return p+p+1;}
	int right(int p){return p+p+2;}
	std::vector< std::vector<int> > st;
	std::vector<int> a;
	int n;

	void build(int ind, int l, int r)
	{
		if(l==r)
		{
			st[ind].push_back(a[l]);
			return;
		}

		int mid=(l+r)/2;
		int left_ind = left(ind);
		int right_ind = right(ind);


		build(left_ind, l, mid);
		build(right_ind, mid+1, r);

		st[ind] = std::vector<int>(r-l+1, 0);
		std::merge(
			st[left_ind].begin(), st[left_ind].end(), 
			st[right_ind].begin(), st[right_ind].end(),
			st[ind].begin());
	}

	int qry(int ind, int l, int r, int i, int j, int k)
	{
		if(r<i || l>j)
			return 0;
		else if(l==r)
		{
			return a[l]==k;
		}

		//std::cout << "on (" << ind << ", " << l << ", " << r << ")\n";

		int mid = (l+r)/2;
		int left_ind = left(ind);
		int right_ind = right(ind);

		int ans;
		if(l<i || r>j)
		{
			ans=qry(left_ind, l, mid, i, j, k) +
				qry(right_ind, mid+1, r, i, j, k);
		}
		else
		{
			std::vector<int>::iterator it1, it2;
			it1=upper_bound(st[ind].begin(), st[ind].end(), k);
			it2=lower_bound(st[ind].begin(), st[ind].end(), k);
			ans=int(it1-it2);
		}
		//std::cout << "on " << ind << " returning " << ans << '\n';
		return ans;
	}
};

typedef long long ll;

int main()
{
	int n;
	ll k;
	std::vector<int> a;
	std::cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		int temp;
		scanf("%i",&temp);
		a.push_back(temp);
	}
	Small_Tree st(a);
	ll ans=0;
	for(int i=1;i<n-1;i++)
	{
		if(abs(a[i])%k==0 && abs(a[i])*k<=int(1e9))
			ans+=(ll)st.qry(0, i-1, a[i]/k)*(ll)st.qry(i+1, n-1, a[i]*k);
	}
	std::cout << ans << '\n';
}