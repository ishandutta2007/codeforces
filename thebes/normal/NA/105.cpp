#include <bits/stdc++.h>
using namespace std;

string out;
int n, k, cnt, a, b, i;

int main(){
	scanf("%d%d%d%d",&n,&k,&a,&b);
	for(i=1;i<=n;i++){
		int mx=(a>=b)?-1:1;
		int m=(a>=b)?0:1;
		if(abs(cnt+mx)>k){
			(!m)?b--:a--;
			cnt = -mx;
			out.push_back((!m)?'B':'G');
		}
		else{
			if(cnt*mx<0) cnt = mx;
			else cnt += mx;
			(!m)?a--:b--;
			out.push_back((!m)?'G':'B');
		}
		if(a<0||b<0){
			printf("NO\n");
			return 0;
		}
	}
	printf("%s\n",out.c_str());
	return 0;
}