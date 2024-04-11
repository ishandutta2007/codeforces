#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int p[MN], s[MN], N, i, ans=1<<30;
string str;

int main(){
	cin >> str; N=str.size();
	for(i=1;i<=N;i++)
		p[i]=p[i-1]+(str[i-1]>='a'&&str[i-1]<='z');
	for(i=N;i>=1;i--)
		s[i]=s[i+1]+(str[i-1]>='A'&&str[i-1]<='Z');
	for(i=1;i<=N;i++)
		ans=min(ans,s[i+1]+p[i-1]);
	printf("%d\n",ans);
	return 0;
}