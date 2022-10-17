#include <cstdio>
#include <cstring>

const int A = 26;
const int N = 100000;
int t, amt[A], cpy[A];
char s[N + 1];

int main() 
{
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		memset(amt, 0, A << 2);
		int d = 0;
		for (int i = 0; s[i]; ++i) {
			if (!amt[s[i] - 'a']) ++d;
			++amt[s[i] - 'a'];
		}
		int mn = ~(1 << 31), ind;
		for (int i = 0; i < A; ++i) if (amt[i] && amt[i] < mn) {
			mn = amt[i];
			ind = i;
		}
		if (mn == 1 || d == 1) {
			if (mn == 1) {
				printf("%c", 'a' + ind);
				--amt[ind];
			}
			for (int i = 0; i < A; ++i) while (amt[i]) {
				printf("%c", 'a' + i);
				--amt[i];
			}
		}
		else {
			memcpy(cpy, amt, A << 2);
			int fi;
			for (fi = 0; !amt[fi]; ++fi);
			s[0] = s[1] = 'a' + fi;
			amt[fi] -= 2;
			int next;
			for (next = fi + 1; !amt[next]; ++next);
			bool ok = true;
			for (int i = 2; s[i] && ok; ++i) {
				if (amt[fi] && s[i - 1] != 'a' + fi) {
					s[i] = 'a' + fi;
					--amt[fi];
				}
				else {
					while (next < A && !amt[next]) ++next;
					if (next == A) ok = false;
					else {
						s[i] = 'a' + next;
						--amt[next];
					}
				}
			}
			if (ok) printf("%s", s);
			else {
				memcpy(amt, cpy, A << 2);
				for (next = fi + 1; !amt[next]; ++next);
				printf("%c%c", 'a' + fi, 'a' + next);
				--amt[fi];
				--amt[next];
				if (d == 2) {
					while (amt[next]) {
						printf("%c", 'a' + next);
						--amt[next];
					}
					while (amt[fi]) {
						printf("%c", 'a' + fi);
						--amt[fi];
					}
				}
				else {
					int nextnext;
					for (nextnext = next + 1; !amt[nextnext]; ++nextnext);
					while (amt[fi]) {
						printf("%c", 'a' + fi);
						--amt[fi];
					}
					printf("%c", 'a' + nextnext);
					--amt[nextnext];
					for (int i = 0; i < A; ++i) while (amt[i]) {
						printf("%c", 'a' + i);
						--amt[i];
					}
				}
			}
		}
		printf("\n");
	}
	return 0;
}