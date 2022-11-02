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
#include <functional>

std::map<std::string,std::pair<int,int> >mm;
int n,m,tt;
bool was[100][100];
std::string s;
char S[1000];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d\n",&n,&m,&tt);
	memset(was,false,sizeof(was));
	for (tt;tt;tt--){
		char q;
		int x,y;
		scanf("%c %d ",&q,&x);
		if (q=='+')scanf("%d %d ",&x,&y);
		gets(S);
		S[strlen(S)]=0;
		s=std::string(S);
		if (q=='+'){
			while (was[x][y]){
				y++;
				if (y>m){
					y=1;
					x++;
				}
				if (x>n)break;
			}
			if (x>n)continue;
			was[x][y]=true;
			mm[s]=std::make_pair(x,y);
		}else{
			x=mm[s].first;
			y=mm[s].second;
			if (x<1)
				puts("-1 -1");
			else{
				printf("%d %d\n",x,y);
				was[x][y]=false;
			}
			mm[s].first=0;
			mm[s].second=0;
		}
	}
	return 0;
}