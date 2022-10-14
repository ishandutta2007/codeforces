#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, q, t[100005];
LL pw[100005];

struct segt
{
	pair<LL, int> dat[800005];
	LL lzy[800005];
	
	void upd(int cv, LL v) {
		dat[cv].first -= v; lzy[cv] += v;
	}
	
	void push(int cv) {
		upd(cv << 1, lzy[cv]);
		upd(cv << 1 | 1, lzy[cv]);
		lzy[cv] = 0;
	}
	
	void build(int cv = 1, int cl = 1, int cr = n) {
		if(cl == cr) {
			dat[cv] = MP(pw[cl] - t[cl], cl); return;
		}
		int mid = cl + cr >> 1;
		build(cv << 1, cl, mid);
		build(cv << 1 | 1, mid + 1, cr);
		dat[cv] = min(dat[cv << 1], dat[cv << 1 | 1]);
	}
	
	LL query(int id, int cv = 1, int cl = 1, int cr = n) {
		if(cl == cr) return dat[cv].first;
		int mid = cl + cr >> 1;
		push(cv);
		if(id <= mid) return query(id, cv << 1, cl, mid);
		else return query(id, cv << 1 | 1, mid + 1, cr);
	}

	void add(int l, int r, int x, int cv = 1, int cl = 1, int cr = n) {
		if(cl > cr || cl > r || cr < l) return;
		if(l <= cl && cr <= r) {
			upd(cv, x); push(cv); return;
		}
		push(cv);
		int mid = cl + cr >> 1;
		add(l, r, x, cv << 1, cl, mid);
		add(l, r, x, cv << 1 | 1, mid + 1, cr);
		dat[cv] = min(dat[cv << 1], dat[cv << 1 | 1]);
	}
	
	void update(int id, LL v, int cv = 1, int cl = 1, int cr = n) {
		if(cl == cr) {
			dat[cv] = MP(v, cl); return;
		}
		push(cv);
		int mid = cl + cr >> 1;
		if(id <= mid) update(id, v, cv << 1, cl, mid);
		else update(id, v, cv << 1 | 1, mid + 1, cr);
		dat[cv] = min(dat[cv << 1], dat[cv << 1 | 1]);
	}
} tre;

set<int> pos;
void cut(int id)
{
	if(id > n) return;
	set<int>::iterator it = pos.lower_bound(id + 1);
	-- it;
	int i = *it; pw[id] = pw[i];
	tre.update(id, tre.query(i));
	pos.insert(id);
}

int main()
{
	scanf("%d%d", &n, &q);
	rep1(i, n) {
		scanf("%d", &t[i]);
		pw[i] = 1; while(pw[i] < t[i]) pw[i] *= 42;
		pos.insert(i);
	}
	tre.build();
	//printf("%lld\n", tre.query(4));
	
	while(q --) {
		int op;
		scanf("%d", &op);
		if(op == 1) {
			int i;
			scanf("%d", &i);
			set<int>::iterator it = pos.lower_bound(i + 1);
			-- it;	i = *it;
			printf("%lld\n", pw[i] - tre.query(i));
		} else if(op == 2) {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			cut(r + 1);
			while(true) {
				set<int>::iterator it = pos.lower_bound(l);
				if(it == pos.end() || *it > r) break;
				tre.update(*it, 1e16);
				pos.erase(it);
			}
			pos.insert(l);
			t[l] = x;
			pw[l] = 1;
			while(pw[l] < t[l]) pw[l] *= 42;
			tre.update(l, pw[l] - t[l]);
		} else {
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			cut(l); cut(r + 1);
			tre.add(l, r, x);
			//printf("??????? %lld\n ??????", tre.query(4));
			while(tre.dat[1].first <= 0) {
				int id = tre.dat[1].second;
				if(tre.dat[1].first < 0) {
					LL val = pw[id] - tre.query(id);
					//printf("fixam %d   %lld         %lld        %lld\n", id, val, pw[id], tre.dat[1].first);
					while(pw[id] < val) pw[id] *= 42;
					tre.update(id, pw[id] - val);
				} else {
					//printf("WTF SI TI?? %d\n", id);
					//printf("OH NO!\n");
					tre.add(l, r, x);
				}
			}
		}
	}
	return 0;
}