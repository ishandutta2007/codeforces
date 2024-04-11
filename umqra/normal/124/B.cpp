#include <iostream>
#include <string>
#include <vector>
using namespace std;
int per[50000][10];
int mas[10];
string stroki[10];
bool used[10];
int n, k, ind;
void gen ( int in )
{
	if ( in==k )
	{
		for ( int i=0; i<k; i++ )
			per[ind][i]=mas[i];
		ind++;
	}
	for (int i=1; i<=k; i++ )
	{
		if ( used[i]==false )
		{
			used[i]=true;
			mas[in]=i;
			gen ( in+1 );
			mas[in]=0;
			used[i]=false;
		}
	}
}
string po( int i, int j )
{
	string str=stroki[j];
	string str2=stroki[j];
	for ( int s=0; s<10; s++ )
	{
		if ( per[i][s]==0 )
			break;
		str2[s]=str[per[i][s]-1];
	}
	return str2;
}
int in ( string str )
{
	int rez=0;
	for ( int i=0; i<str.length(); i++ )
	{
		int ch=str[i]-'0';
		rez*=10;
		rez+=ch;
	}
	return rez;
}
int main()
{
	int rez=-1;
	cin >> n >> k;
	gen(0);
	for ( int i=0; i<n; i++ )
		cin >> stroki[i];
	for ( int i=0; i<ind; i++ )
	{
		int mi=-1, ma=-1;
		for ( int s=0; s<n; s++ )
		{
			string pom=po(i, s);
			int r=in(pom);
			if ( r>ma )
				ma=r;
			if ( r<mi||mi==-1 )
				mi=r;
		}
		if ( rez==-1||rez>ma-mi )
			rez=ma-mi;
	}
	cout << rez;
	return 0;
}

/*

8 8
52375237
27535237
75235237
57235237
53275237
25375237
52375237
27535237



*/