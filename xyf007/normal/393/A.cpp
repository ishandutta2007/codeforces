#include<bits/stdc++.h>
using namespace std;
string s;
void checkmin(int &x,int y)
{
	if(x>y)
	  x=y;
}
int main()
{
	cin>>s;
	int N=0,I=0,E=0,T=0,ans=2e9;
	for(int i=0;i<s.size();i++)
	  {
	  	if(s[i]=='n')
	  	  N++;
	  	if(s[i]=='i')
	  	  I++;
	  	if(s[i]=='e')
	  	  E++;
	  	if(s[i]=='t')
	  	  T++;
	  }
	checkmin(ans,(N-1)/2);
	checkmin(ans,I);
	checkmin(ans,E/3);
	checkmin(ans,T);
	printf("%d",ans);
	return 0;
}