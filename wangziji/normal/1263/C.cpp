#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <int> v;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		v.clear();
		cin >> n;
		for(int i=0;i*i<=n;i++) 
			v.push_back(i);
		for(int i=sqrt(n)+10000;i>=1;i--)
		{
			if(n/i>v[v.size()-1])
				v.push_back(n/i);
		}
		cout << v.size() << endl;
		for(int i=0;i<v.size();i++)
			cout << v[i] << " ";
		cout << endl;
	}
	return 0;
}