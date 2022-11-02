#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>

const int hx[]={1,1,2,2,-1,-1,-2,-2};
const int hy[]={2,-2,1,-1,2,-2,1,-1};

int res;
char s[10];
int ax, ay,bx,by;

int main(){
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	gets(s);
	ax=s[0]-'a';
	ay=s[1]-49;
	gets(s);
	bx=s[0]-'a';
	by=s[1]-49;
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
			if (i!=ax&&j!=ay){
				if (i==bx&&j==by)continue;
				int q=0;
				while (q<8){
					int cx,cy;
					cx=i+hx[q];
					cy=j+hy[q];
					if (cx==bx&&cy==by)break;
					if (cx==ax&&cy==ay)break;
					q++;
				}
				if (q==8)res++;
			}
	printf("%d\n",res);
	return 0;
}