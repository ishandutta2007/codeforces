#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;

const long long mod=1000000007;

mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B[0].size(),0));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<A[0].size();k++)
			{
				C[i][j]+=(A[i][k]*B[k][j]);
				C[i][j]%=mod;
			}
		}
	}
	return C;
}

mat pown(mat &A,long long n)
{
	mat res(A.size(),vec(A.size(),0));
	for(int i=0;i<A.size();i++) res[i][i]=1;
	if(n==0) return res;
	mat AA=pown(A,n/2);
	res=mul(res,AA);
	res=mul(res,AA);
	if(n%2==1) return mul(res,A);
	return res;
}

int getnum(char ch)
{
	if(ch>='a'&&ch<='z') return ch-'a';
	else return ch-'A'+26;
}

int main()
{
	long long N;
	int M,K;
	cin>>N>>M>>K;
	mat A(M,vec(M,1));
	for(int i=0;i<K;i++)
	{
		string str;
		cin>>str;
		int a=getnum(str[0]),b=getnum(str[1]);
		A[a][b]=0;
	}
	mat res=pown(A,N-1);
	long long ans=0;
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<M;j++)
		{
			ans+=res[i][j];
			ans%=mod;
		}
	}
	ans+=mod;
	ans%=mod;
	cout<<ans<<"\n";
	return 0;
}