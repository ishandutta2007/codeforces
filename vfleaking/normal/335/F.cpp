#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000ll;

const int MaxN = 500000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int treap_x = 233;
inline int treap_rand()
{
	return treap_x = (treap_x * 69343957ll + 192737) % 1000000007;
}

struct treap
{
	int size;
	s64 last;

	s64 tag_a, tag_b;

	int pri;
	s64 val;
	treap *lc, *rc;

	inline void init(s64 val)
	{
		this->val = val, this->pri = treap_rand();
		this->tag_a = 0, this->tag_b = 0;
		this->lc = this->rc = NULL;
		this->update();
	}

	inline void update()
	{
		this->size = 1;
		if (this->lc)
			this->size += this->lc->size;
		if (this->rc)
			this->size += this->rc->size;
		this->last = this->rc ? this->rc->last : val;
	}

	inline void tag_trans(s64 a, s64 b)
	{
		this->tag_a += a, this->tag_b += b;
		last += (s64)(this->size - 1) * a + b;
	}

	inline void tag_down()
	{
		if (this->tag_a != 0 || this->tag_b != 0)
		{
			int lsize = this->lc ? this->lc->size : 0;
			if (this->lc)
				this->lc->tag_trans(this->tag_a, this->tag_b);
			val += (s64)lsize * this->tag_a + this->tag_b;
			if (this->rc)
				this->rc->tag_trans(this->tag_a, (s64)(lsize + 1) * this->tag_a + this->tag_b);

			this->tag_a = this->tag_b = 0;
		}
	}

	s64 get(int k)
	{
		this->tag_down();
		int lsize = this->lc ? this->lc->size : 0;
		if (k < lsize)
			return this->lc->get(k);
		else if (k > lsize)
			return this->rc->get(k - lsize - 1);
		else
			return this->val;
	}
	void set(int k, s64 val)
	{
		this->tag_down();
		int lsize = this->lc ? this->lc->size : 0;
		if (k < lsize)
			this->lc->set(k, val);
		else if (k > lsize)
			this->rc->set(k - lsize - 1, val);
		else
			this->val = val;
		this->update();
	}

	int findGap(s64 last = INF)
	{
		this->tag_down();
		s64 lastv = this->lc ? this->lc->last : last;
		if (lastv > val)
			return (this->lc ? this->lc->size : 0) + 1 + (this->rc ? this->rc->findGap(val) : 0);
		else
			return this->lc ? this->lc->findGap(last) : 0;
	}

	static treap *merge(treap *p, treap *q)
	{
		if (!p)
			return q;
		if (!q)
			return p;
		p->tag_down(), q->tag_down();
		if (p->pri < q->pri)
		{
			p->rc = merge(p->rc, q), p->update();
			return p;
		}
		else
		{
			q->lc = merge(p, q->lc), q->update();
			return q;
		}
	}

	pair<treap*, treap*> split(int k)
	{
		this->tag_down();
		int lsize = this->lc ? this->lc->size : 0;
		if (k < lsize)
		{
			pair<treap*, treap*> res = this->lc->split(k);
			this->lc = res.second, this->update(), res.second = this;
			return res;
		}
		else if (k > lsize)
		{
			pair<treap*, treap*> res = this->rc ? this->rc->split(k - lsize - 1) : make_pair((treap*)NULL, (treap*)NULL);
			this->rc = res.first, this->update(), res.first = this;
			return res;
		}
		else
		{
			treap *lp = this->lc;
			this->lc = NULL, this->update();
			return make_pair(lp, this);
		}
	}
};

int main()
{
	int n;
	static int a[MaxN], b[MaxN];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);

	int old_n = n;
	n = 0;
	for (int i = 0, j = 0; i < old_n; i = j)
	{
		while (j < old_n && a[i] == a[j])
			j++;
		a[n] = a[i], b[n] = j - i, n++;
	}

	static treap treap_pool[MaxN + 1], *treap_tail = treap_pool;

	treap *f = treap_tail++;
	f->init(0);
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		int off = (old_n - len - b[i]) % 2;
		int dif = (old_n - len) % 2;
		int nep = (b[i] + dif) / 2;
		int cur_n = (len + b[i] - old_n % 2) / 2;

		f->tag_trans(a[i], (s64)nep * a[i]);
		int p = f->findGap() - 1;
		for (int j = 0; j < nep; j++)
		{
			treap *p = treap_tail++;
			p->init(0), f = treap::merge(p, f);
		}
		p += nep;

		for (int j = 0; j < nep; j++)
		{
			int l = b[i] - j - (off + 1) / 2, r = min(b[i] + j, cur_n);
			if (l <= r)
			{
				if (r <= p)
					f->set(j, f->get(r));
				else if (l <= p)
					f->set(j, f->get(p));
				else
					f->set(j, f->get(l));
			}
			else
				f->set(j, (s64)(b[i] - j - (off + 1) / 2) * a[i]);
		}

		s64 fp = f->get(p);

		if (nep + b[i] <= p)
		{
			pair<treap*, treap*> sp1 = f->split(p);
			pair<treap*, treap*> sp2 = sp1.first->split(nep);
			pair<treap*, treap*> sp3 = sp2.second->split(b[i]);
			for (int j = 0; j < b[i]; j++)
				sp3.first->set(j, fp);
			f = treap::merge(treap::merge(treap::merge(sp2.first, sp3.second), sp3.first), sp1.second);
		}
		else
		{
			for (int j = nep; j < p; j++)
				f->set(j, fp);
		}

		f->tag_trans(-a[i], 0);
		len += b[i];
	}
	cout << f->get(0) << endl;

	return 0;
}