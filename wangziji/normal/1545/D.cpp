#include <iostream>
#define int long long
using namespace std;
int a[1005][1005],s[1005],ss[1005];
signed main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
		for(int j=1;j<=n;j++)
			cin >> a[i][j];
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
			s[i]+=a[i][j];
	}
	int L=s[0],R=s[m-1],D=(R-L)/(m-1),T=0,di=0;
	for(int i=1;i<m-1;i++)
	{
		if(s[i]!=s[i-1]+D)
		{
			T=i,di=s[i-1]+D-s[i];
			break;
		}
	}
	cout << T << " ";
	int A,B,C;
	for(int j=0;j<m;j++)
		for(int i=1;i<=n;i++) ss[j]+=a[j][i]*a[j][i];
	A=ss[0];
	int qwq=1;
	if(T==qwq) ++qwq;
	int x2=ss[m-1]-A,x1=ss[qwq]-A,x3=qwq*x2-(m-1)*x1;
	C=x3/(qwq*(m-1)*(m-1)-(m-1)*qwq*qwq);
	B=(ss[qwq]-qwq*qwq*C-A)/qwq/2;
	for(int i=0;i<m;i++)
	{
		int G=A+i*2*B+i*i*C;
		if(ss[i]!=G)
		{
			for(int j=1;j<=n;j++)
			{
				if(ss[i]-a[i][j]*a[i][j]+(a[i][j]+di)*(a[i][j]+di)==G)
				{
					cout << a[i][j]+di << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}