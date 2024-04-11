#include <cstdio>
#include <cstdlib>

typedef unsigned long long ull;

char ex[5010];
int ms[20];
int m_n;

inline bool legal(int i) { return i >= 0 && ex[i]; }
ull eval(int from, int to) {
	if(!legal(from) || !legal(to)) return 0;
	ull val = 0;
	int i;
	while(from <= to) {
		// printf("from(%d) -> %c\n", from, ex[from]);
		ull l = ex[from] - '0';
		for(i = from + 1; i <= to && ex[i] == '*'; i += 2)
			l *= ex[i + 1] - '0';
		val += l;
		// printf("l | %I64u | val %I64u | i %d\n", l, val, i + 1);
		from = i + 1;
	}
	return val;
}



int main() {
	int i, j, k;
	scanf(" %s", ex);
	m_n = 0;
	ms[m_n++] = -1;
	int size;
	for(size = 0; ex[size]; size++)
		if(ex[size] == '*')
			ms[m_n++] = size;
	ms[m_n++] = size;
	ull val_max = 0;
	for(i = 0; i < m_n; i++)
		for(j = i + 1; j < m_n; j++) {
			// printf("from %d to %d\n", ms[i], ms[j]);
			ull val = 0;
			ull left = 1, right = 1;
			if(legal(ms[i])) left = ex[ms[i] - 1] - '0';
			int k_l;
			for(k_l = ms[i] - 2; legal(k_l) && ex[k_l] == '*'; k_l -= 2)
				left *= ex[k_l - 1] - '0';
			// printf("left | %I64u\n", left);
			if(legal(ms[j])) right = ex[ms[j] + 1] - '0';
			int k_r;
			for(k_r = ms[j] + 2; legal(k_r) && ex[k_r] == '*'; k_r += 2)
				right *= ex[k_r + 1] - '0';
			// printf("right | %I64u\n", right);
			ull center = eval(ms[i] + 1, ms[j] - 1);
			// printf("center | %I64u\n", center);
			val = eval(0, k_l - 1) + left * center * right + eval(k_r + 1, size - 1);
			// printf("val %I64u\n\n\n", val);
			if(val > val_max) val_max = val;
		}
	printf("%I64u\n", val_max);
	return 0;
}