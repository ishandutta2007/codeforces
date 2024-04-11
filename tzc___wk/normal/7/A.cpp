#include <bits/stdc++.h>
using namespace std;
const int inf=12;
int main()
{
	char s[10][10];
	int a=0,b=inf,num=0;
    for(int i=0;i<8;++i)
    {
    	num=0;
        for(int j=0;j<8;++j)
        {
        	cin>>s[i][j];
        	if(s[i][j]=='B')
        	{
        		num++;
			}
		}
		if(num==8)
		{
			a++;
		}
		b=min(b,num);
    }
    int ans=a+b;
    if(ans==16)	ans=8;
    cout<<ans<<endl;
    return 0;
}