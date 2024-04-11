#include <stdio.h>
#include <algorithm>
const int N=100050;
int S[N],cnt,tmp;
int main()
{
	int n,x;
	scanf("%i",&n);
	while(n--){
		scanf("%i",&x);
		tmp=std::upper_bound(S,S+cnt,x)-S;
		if(tmp==cnt) cnt++;
		S[tmp]=x;
	}
	printf("%i\n",cnt);
	return 0;
}