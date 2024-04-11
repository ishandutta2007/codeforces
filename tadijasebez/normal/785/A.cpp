#include <stdio.h>
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
map<string,int> mapa;
string s;
int ans;
int main()
{
	mapa["Tetrahedron"]=4;
	mapa["Cube"]=6;
	mapa["Octahedron"]=8;
	mapa["Dodecahedron"]=12;
	mapa["Icosahedron"]=20;
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		cin >> s;
		ans+=mapa[s];
	}
	printf("%i\n",ans);
	return 0;
}