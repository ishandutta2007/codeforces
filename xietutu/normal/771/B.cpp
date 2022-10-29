#include<iostream>
#include<cstdio>

using namespace std;

int n,k;
int a[100];
char S[100];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<k;i++) a[i]=i;
	int cnt=k-1;
	for (int i=k;i<=n;i++) 
	{
		scanf("%s",S);
		if (S[0]=='Y') 
		{
			++cnt;
			a[i]=cnt;
		}
		else a[i]=a[i-k+1];
	} 
	for (int i=1;i<=n;i++)
	{
		cout << 'A';
		if (a[i]<=26) cout << (char)('a'+a[i]-1);
		else {
			
			cout << 'b' << (char)('a'+(a[i]-26)-1);
		}
		cout<< ' ';
	}
	return 0;
}