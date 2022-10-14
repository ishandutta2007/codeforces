// Author : WangZhikun
// Date   : 2018.08.03

#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

int u[500050],v[500050];
int n,m;
bitset<4020> al[2020];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i];
		al[u[i]-1].set(v[i]-1);
	}
	for(int i=0;i<n;i++)al[i][n+i] = 1;
	int e = 1;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++)
			if(al[j].test(i)){
				swap(al[i],al[j]);
				break;
			}
		if(!al[i].test(i))e = 0;
		for(int j=0;j<n;j++)
			if(al[j].test(i)&&j!=i)
				al[j]^=al[i];
	}
	for(int i=0;i<m;i++){
		cout<<((e*al[v[i]-1].test(u[i]-1+n))?"NO":"YES")<<endl;
	}
	return 0;
}