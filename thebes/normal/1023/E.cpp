#include <bits/stdc++.h>
using namespace std;

const int MN = 505;
int x, y, i, n, ox, oy;
string s, a, b;

bool qu(int a,int b,int c,int d){
	printf("? %d %d %d %d\n",a,b,c,d);
	fflush(stdout);
	cin >> s;
	return s=="YES";
}

int main(){
	scanf("%d",&n);
	for(x=y=1;x+y<=n;){
		if(x+1<=n){
			if(qu(y,x+1,n,n)){
				a.push_back('R');
				x++;
			}
			else{
				a.push_back('D');
				y++;
			}
		}
		else a.push_back('D'), y++;
	}
	ox = x, oy = y;
	for(x=y=n;x+y-2>n;){
		if(y-1>=1){
			if(!qu(1,1,y-1,x)){
				b.insert(b.begin(),'R');
				x--;
			}
			else{
				b.insert(b.begin(),'D');
				y--;
			}
		}
		else b.insert(b.begin(),'R'), x--;
	}
	if(ox==x) a.push_back('D');
	else a.push_back('R');
	printf("! %s%s\n",a.c_str(),b.c_str());
	fflush(stdout);
	getchar(); getchar();
	return 0;
}