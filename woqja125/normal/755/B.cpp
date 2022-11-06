#include<stdio.h>
#include<string>
#include<set>
using namespace std;
set<string> A;
char t[1000];
int main(){
	int n, m, b=0;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++){
		scanf("%s", t);
		A.insert(string(t));
	}
	for(int i=1; i<=m; i++){
		scanf("%s", t);
		if(A.count(string(t))==1) b++;
	}
	if(b%2 == 0) printf(n>m?"YES":"NO");
	else printf(n>=m?"YES":"NO");
	return 0;
}