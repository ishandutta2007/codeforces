#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<string, int64_t> X;
	X["Tetrahedron"]=4;
	X["Cube"]=6;
	X["Octahedron"]=8;
	X["Dodecahedron"]=12;
	X["Icosahedron"]=20;
	int64_t N;
	cin>>N;
	int64_t ans=0;
	for(int64_t i=0;i<N;i++)
	{
		string a;
		cin>>a;
		ans+=X[a];
	}
	cout<<ans;
	return 0;
}