#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;

char a[4]={118,60,94,62};

int main() {
	char c1,c2;
	int n;
	scanf("%c %c %d",&c1,&c2,&n);
	
	int st=0;
	for(;st<4;st++) if(a[st]==c1) break;
	int af=0,bf=0;
	if(a[(st+n%4)%4]==c2) {
		af=1;
	}
	if(a[(st-n%4+4)%4]==c2) {
		bf=1;
	}
	if(af==bf) puts("undefined");
	else if(af) puts("cw");
	else puts("ccw");
}