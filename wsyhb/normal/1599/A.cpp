#include<bits/stdc++.h>
using namespace std;
const int max_N=2e5+5;
int A[max_N],ans[max_N];
char S[max_N],str[max_N];
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		scanf("%d",A+i);
	sort(A+1,A+N+1);
	scanf("%s",S+1);
	str[N]=S[N];
	for(int i=N-1;i>=1;--i)
		str[i]=str[i+1]^'L'^'R';
	int l=1,r=N;
	for(int i=N;i>=1;--i)
		ans[i]=(S[i]!=S[i-1]?r--:l++);
	for(int i=1;i<=N;++i)
		printf("%d %c\n",A[ans[i]],str[ans[i]]);
	return 0;
}