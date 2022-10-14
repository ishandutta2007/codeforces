#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	scanf("%i",&tt);
	while(tt--){
		string s;
		cin >> s;
		map<pair<pair<int,int>,pair<int,int> >,int> done;
		int t=0;
		int x=0,y=0;
		for(auto p:s){
			pair<int,int> lst={x,y};
			if(p=='N')
				x++;
			if(p=='S')
				x--;
			if(p=='W')
				y++;
			if(p=='E')
				y--;
			pair<int,int> sad={x,y};
			if(done[{lst,sad}])
				t++;
			else
				t+=5;
			done[{lst,sad}]=1;
			done[{sad,lst}]=1;
		}
		printf("%i\n",t);
	}
	return 0;
}