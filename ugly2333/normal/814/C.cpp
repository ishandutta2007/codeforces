// CF 814C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
char s[1111];
int n,ans[2222][33];
int solve(int k,int cc)
{
	int i,j,ss,cur;
	ss=k;
	i=1;
	j=0;
	cur=0;
	while(j<=n){
		if(cur<k||(j<n&&s[j+1]==cc)){
			j++;
			if(j>n)
				break;
			if(s[j]!=cc)
				cur++;
		}
		else{
			if(s[i]!=cc)
				cur--;
			i++;
		}
		ss=max(ss,j-i+1);
	}
	return ss;
}
int main()
{
	int i,q;
	char cc;
	cin>>n>>s;
	for(i=n;i>=1;i=i-1)
		s[i]=s[i-1];
	for(i=1;i<=n;i=i+1)
		for(cc='a';cc<='z';cc=cc+1)
			ans[i][cc-'a'+1]=solve(i,cc);
	cin>>q;
	while(q--){
		cin>>i>>cc;
		cout<<ans[i][cc-'a'+1]<<endl;
	}
	return 0;
}