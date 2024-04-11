#include <iostream>
#include <map>
using namespace std;
map <pair<pair<int,int>,pair<int,int> >,int> mp;
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		mp.clear();
		string a;
		cin >> a;
		int x=0,y=0,ans=0;
		for(auto qwq:a)
		{
			int nx=x,ny=y;
			if(qwq=='N') ++nx;
			if(qwq=='S') --nx;
			if(qwq=='W') ++ny;
			if(qwq=='E') --ny;
			if(mp[{{x,y},{nx,ny}}]) ++ans;
			else ans+=5,mp[{{x,y},{nx,ny}}]=mp[{{nx,ny},{x,y}}]=1;
			x=nx,y=ny;
		}
		cout << ans << "\n";
	}
	return 0;
}//DLSTXDY!