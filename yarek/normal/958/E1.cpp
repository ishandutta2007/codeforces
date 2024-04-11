#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define PII pair <int, int>

const int N = 13;

int n, m;
PII A[N];
PII B[N];
int perm[N];
bool ok[N][N][N][N];

bool Iloczyn(PII a, PII b, PII c){
	return (b.st - a.st) * (c.nd - a.nd) - (c.st - a.st) * (b.nd - a.nd) < 0;
}

bool intersect(int a, int b, int c, int d){
	if(a == c || b == d)
		return true;
	return Iloczyn(A[a], B[b], A[c]) != Iloczyn(A[a], B[b], B[d]);
}

int main(){
	scanf("%d %d", &n, &m);
	if(n != m){
		puts("No");
		return 0;
	}
	
	puts("Yes");
	return 0;
	
	for(int i = 1; i <= n; ++i)
		scanf("%d %d", &A[i].st, &A[i].nd);
	
	for(int i = 1; i <= m; ++i)
		scanf("%d %d", &B[i].st, &B[i].nd);
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int ii = 1; ii <= n; ++ii)
				for(int jj = 1; jj <= m; ++jj)
					ok[i][j][ii][jj] = !intersect(i, j, ii, jj) && !intersect(ii, jj, i, j);
	
	for(int i = 1; i <= n; ++i)
		perm[i] = i;
	
	do{
		bool good = true;
		for(int i = 1; i <= n; ++i){
			for(int j = i + 1; j <= n; ++j)
				if(!ok[i][perm[i]][j][perm[j]]){
					good = false;
					break;
				}
			
			if(!good)
				break;
		}
		
		if(good){
			puts("Yes");
			return 0;
		}

	}while(next_permutation(perm + 1, perm + n + 1));
	
	puts("No");
	return 0;
}