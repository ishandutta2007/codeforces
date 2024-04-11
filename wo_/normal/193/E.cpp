#include<cstdio>
#include<vector>
#include<iostream>

using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;

vector<int> two[8192];
vector<long long> five[5];

long long ex[14];//5^i

mat gen(2,vec(2));

long long mod;

mat mul(mat &A,mat &B)
{
	mat C(A.size(),vec(B.size()));
	for(int i=0;i<A.size();i++)
	{
		for(int j=0;j<B[0].size();j++)
		{
			for(int k=0;k<A[0].size();k++)
			{
				C[i][j]+=A[i][k]*B[k][j];
				C[i][j]%=(mod);
				if(C[i][j]>mod/2) C[i][j]-=mod;
				if(C[i][j]<-mod/2) C[i][j]+=mod;
			}
		}
	}
	return C;
}

mat pow(mat &A,long long N)
{
	mat res(A.size(),vec(A.size()));
	for(int i=0;i<A.size();i++) res[i][i]=1;
	if(N==0) return res;
	mat tmp=pow(A,N/2);
	res=mul(res,tmp);
	res=mul(res,tmp);
	if(N%2==1) res=mul(res,A);
	return res;
}

long long fib(long long N)
{
	mat res=pow(gen,N);
	long long r=res[1][0];
	r%=mod;
	r+=mod;
	r%=mod;
	return r;
}

vector<long long> get(long long r,int e)
{
	if(e==0) return five[r];
	vector<long long> tmp=get(r%ex[e-1],e-1);
	vector<long long> ans;
	for(int i=0;i<tmp.size();i++)
	{
		for(int j=0;j<=4;j++)
		{
			long long n=tmp[i]+ex[e]*j;
			long long f=fib(n);
			if(f%ex[e]==r) ans.push_back(n);
		}
	}
	return ans;
}

int main()
{
	gen[0][0]=1;gen[0][1]=1;gen[1][0]=1;
	ex[0]=1;
	for(int i=1;i<=13;i++) ex[i]=ex[i-1]*5;
	mod=ex[13];
	long long prev[2];
	two[0].push_back(0);
	two[1].push_back(1);
	prev[0]=0;prev[1]=1;
	for(int i=2;i<12288;i++)
	{
		long long tmp=prev[0]+prev[1];
		tmp%=8192;
		two[tmp].push_back(i);
		prev[0]=prev[1];
		prev[1]=tmp;
	}
	prev[0]=0;prev[1]=1;
	five[0].push_back(0);five[1].push_back(1);
	for(int i=2;i<20;i++)
	{
		long long tmp=prev[0]+prev[1];
		tmp%=5;
		five[tmp].push_back(i);
		prev[0]=prev[1];
		prev[1]=tmp;
	}
	long long in;
	cin>>in;
	int ord=0;
	//long long f=in;
	//while(f%5==0)
	//{
	//	ord++;
	//	f/=5;
	//}
	vector<long long> a=get(in,13-ord);
	for(int i=0;i<a.size();i++) a[i]*=ex[ord];
	vector<long long> v[20];
	//v[1]=five[f%5];
	v[1]=five[in%5];
	//for(int i=2;i<=13-ord;i++)
	for(int i=2;i<=13;i++)
	{
		for(int j=0;j<v[i-1].size();j++)
		{
			for(int k=0;k<5;k++)
			{
				long long id=v[i-1][j]+ex[i-1]*k*4;
				long long m=fib(id)%ex[i];
				//if(f%ex[i]==m) v[i].push_back(id);
				if(in%ex[i]==m) v[i].push_back(id);
			}
		}
	}
	long long ans=100000000000000;
	//for(int i=0;i<v[13-ord].size();i++)
	for(int i=0;i<v[13].size();i++)
	{
		for(int j=0;j<two[in%8192].size();j++)
		{
			//long long f=v[13-ord][i]*ex[ord];
			long long f=v[13][i];
			long long t=two[in%8192][j];
			if(f==9748535156230%(ex[13]*4)) printf("yes\n");
			for(;f<8192ll*3/2*ex[13];f+=4ll*ex[13])
			{
				if(f%(8192*3/2)==t)
				{
					ans=min(ans,f);
					break;
				}
			}
		}
	}
	if(ans==100000000000000) ans=-1;
	cout<<ans<<"\n";
	return 0;
}