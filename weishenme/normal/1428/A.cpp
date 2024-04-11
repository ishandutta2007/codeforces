#include<bits/stdc++.h>
using namespace std;
#define y1 ___y1
const int N=100005;
int T,x1,y1,x2,y2;
int main(){
	scanf("%d",&T);
	while (T--){
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",abs(x1-x2)+abs(y1-y2)+((x1!=x2&&y1!=y2)?2:0));
	}
}