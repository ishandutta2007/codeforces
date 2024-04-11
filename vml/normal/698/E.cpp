#pragma comment(linker, "/STACK:3200000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

int s, m, h, day, date, month;

bool vis(int year_) {
	return year_ % 400 == 0 || (year_ % 4 == 0 && year_ % 100 != 0);
}

int get_cnt(int m, int y) {
	if (m == 2) {
		if (vis(y)) {
			return 29;
		}

		return 28;
	}

	if (m == 1 || m == 3 || m == 5 || m == 7) {
		return 31;
	}

	if (m == 8 || m == 10 || m == 12) {
		return 31;
	}

	return 30;
}

bool check_corr(int day_, int date_) {
	if (date != -1 && day != -1) {
		if (date != date_ && day_ != day) {
			return false;
		}
	} else {
		if (date != -1 && date != date_) {
			return false;
		}

		if (day != -1 && day_ != day) {
			return false;	
		}
	}

	return true;
}

bool check(int month_, int day_, int date_) {
	if (month != -1 && month_ != month) {
		return false;
	}

	if (date != -1 && day != -1) {
		if (date != date_ && day_ != day) {
			return false;
		}
	} else {
		if (date != -1 && date != date_) {
			return false;
		}

		if (day != -1 && day_ != day) {
			return false;	
		}
	}

	return true;
}

bool conf(int month_, int day_, int date_, int h_, int m_, int s_) {
	if (month != -1 && month_ != month) {
		return false;
	}

	if (h != -1 && h != h_) {
		return false;
	}

	if (m != -1 && m != m_) {
		return false;
	}

	if (s != -1 && s != s_) {
		return false;
	}

	if (date != -1 && day != -1) {
		if (date != date_ && day_ != day) {
			return false;
		}
	} else {
		if (date != -1 && date != date_) {
			return false;
		}

		if (day != -1 && day_ != day) {
			return false;	
		}
	}

	return true;
}

ll go(ll t) {
	int year_ = 1970;
	int month_ = 1;
	int date_ = 1;
	int day_ = 3;
	int s_ = 0;
	int m_ = 0;
	int h_ = 0;

	ll tt = t;

	while (true) {
		ll cnt = 365;
		int c = 365;

		if (vis(year_)) {
			cnt++;
			c++;
		}

		cnt *= 24;
		cnt *= 60;
		cnt *= 60;

		if (t >= cnt) {
			t -= cnt;
			year_++;
			day_ += c;
			day_ %= 7;
		} else {
			break;
		}
	}

	while (true) {
		ll cnt = get_cnt(month_, year_);
		int c = cnt % 7;

		cnt *= 24;
		cnt *= 60;
		cnt *= 60;

		if (t >= cnt) {
			t -= cnt;
			month_++;
			day_ += c;
			day_ %= 7;
		} else {
			break;
		}
	}

	while (true) {
		ll cnt = 24 * 60 * 60;

		if (t >= cnt) {
			t -= cnt;
			date_++;
			day_++;
			day_ %= 7;
		} else {
			break;
		}
	}

	while (true) {
		ll cnt = 60 * 60;

		if (t >= cnt) {
			t -= cnt;
			h_++;
		} else {
			break;
		}
	}

	while (true) {
		ll cnt = 60;

		if (t >= cnt) {
			t -= cnt;
			m_++;
		} else {
			break;
		}
	}

	while (true) {
		ll cnt = 1;

		if (t >= cnt) {
			t -= cnt;
			s_++;
		} else {
			break;
		}
	}

	ll count = 0;

	while (!(h_ == 0 && m_ == 0 && s_ == 0)) {
		if (count != 0 && conf(month_, day_, date_, h_, m_, s_)) {
			return tt + count;
		}

		count++;
		s_++;

		if (s_ == 60) {
			s_ = 0;
			m_++;
		}

		if (m_ == 60) {
			h_++;
			m_ = 0;
		}

		if (h_ == 24) {
			date_++;
			day_++;

			if (day_ == 7) {
				day_ = 0;
			}

			h_ = 0;
		}

		if (date_ == get_cnt(month_, year_) + 1) {
			date_ = 1;
			month_++;
		}

		if (month_ == 13) {
			month_ = 1;
			year_++;
		}
	}

	while (!check(month_, day_, date_)) {
		count += 24 * 60 * 60;
		date_++;
		day_++;

		if (day_ == 7) {
			day_ = 0;
		}

		if (date_ == get_cnt(month_, year_) + 1) {
			month_++;
			date_ = 1;

			if (month_ == 13) {
				month_ = 1;
				year_++;
			}
		}
	}

	while (true) {
		if (count != 0 && conf(month_, day_, date_, h_, m_, s_)) {
			return tt + count;
		}

		count++;
		s_++;

		if (s_ == 60) {
			s_ = 0;
			m_++;
		}

		if (m_ == 60) {
			h_++;
			m_ = 0;
		}

		if (h_ == 24) {
			date_++;
			day_++;

			if (day_ == 7) {
				day_ = 0;
			}

			h_ = 0;
		}

		if (date_ == get_cnt(month_, year_) + 1) {
			date_ = 1;
			month_++;
		}

		if (month_ == 13) {
			month_ = 1;
			year_++;
		}
	}

	return -1;
}

int main() {
	cin >> s >> m >> h >> day >> date >> month;
	if (day != -1) {
		day--;
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		ll t;

		cin >> t;
		//t = (ll)1e12;

		cout << go(t) << endl;
	}

	return 0;
}