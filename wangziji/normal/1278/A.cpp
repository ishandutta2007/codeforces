#include <iostream>
#include <cstring>
using namespace std;
int c[1000],d[1000];
int main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		string a,b;
		cin >> a >> b;
		memset(c,0,sizeof c);
		for(int i=0;i<a.size();i++) c[a[i]]++;
			int flag=0;
		int T=b.size()-a.size();
		for(int i=0;i<=T;i++)
		{
			
		memset(d,0,sizeof d);
			for(int j=i;j<a.size()+i;j++)
			{
				d[b[j]]++;
			}
			for(int j=1;j<=200;j++)
			{
				if(j==200)
				{
					flag=1;
					break;
				}
				if(c[j]!=d[j])   {
			break;}
			}
			if(flag) break;
					}
		if(flag) puts("YES");
		else puts("NO");
	}
	return 0;
}