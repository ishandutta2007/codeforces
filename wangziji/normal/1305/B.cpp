#include <iostream>
using namespace std;
int qzh[1005],hzh[1005];
int main(int argc, char** argv) {
	string a;
	cin >> a;
	int n=a.size();
	a=' '+a;
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='(') qzh[i]=1;
		else hzh[i]=1;
	}
	for(int i=1;i<=n;i++) qzh[i]+=qzh[i-1];
	for(int i=n;i>=1;i--) hzh[i]+=hzh[i+1];
	for(int i=0;i<=n;i++)
	{
		if(qzh[i]==hzh[i+1])
		{
			if(qzh[i]==0)
			{
				cout << 0;
				return 0;
			}
			cout << 1 << "\n" << qzh[i]*2 << endl;
			for(int j=1;j<=i;j++)
			{
				if(a[j]=='(') cout << j << " ";
			}
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==')') cout << j << " ";
			}
		}
	}
	return 0;
}