#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair

int main()
{
	int n;
	vector<pair<int,int>> ps;
	scanf("%i",&n);
	if(n%2==0) return 0*printf("NO\n");
	for(int i=1;i<=2*n;i+=2) ps.pb({i,i+1});
	for(int i=1;i<ps.size();i+=2) swap(ps[i].first,ps[i].second);
	printf("YES\n");
	for(int i=0;i<ps.size();i++) printf("%i ",ps[i].first);
	for(int i=0;i<ps.size();i++) printf("%i ",ps[i].second);
	return 0;
}