#include <cstdio>
#include <algorithm>

using namespace std;

int a[3];
int main() {
	for(int i=0;i<3;i++)scanf("%d",a+i);
	sort(a,a+3);
	if(a[0]==1 || a[1]==2 || (a[0] == 3 && a[2]==3)) puts("YES");
	else {
		if(a[0]==2 && a[1]==4 && a[2]==4) puts("YES");
		else puts("NO");
	}
	return 0;
}