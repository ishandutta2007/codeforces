#include <bits/stdc++.h>
using namespace std;
const int N=1030;
long long a[N],b[N];
long long gr[N][N];
long long n,m;
void print()
{
	for(int i=0;i<n;i++)
	{
        for(int j=0;j<m;j++)
		{
            cout<<gr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin>>n>>m;
	long long g=0;
	for(int i=0;i<n;i++)
	{
         cin>>a[i];
         g^=a[i];
	}
    long long h=0;
    for(int i = 0;i<m;i++)
	{
    	cin>>b[i];
    	h^=b[i];
    }
    if(g==h)
	{
        cout<<"YES"<<endl;
     }
	 else
	 {
         cout<<"NO"<<endl;
         return 0;
     }
     g=g^a[0];
     g=g^b[0];
     gr[0][0]=g;
     
     for(int i=1;i<n;i++)
	 {
        gr[i][0]=a[i];
     }
     for(int i=1;i<m;i++)
        gr[0][i]=b[i];
    print();
    return 0;
}