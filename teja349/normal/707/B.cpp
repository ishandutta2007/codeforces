#include <iostream>
using namespace std;
typedef struct {
	int u;
	int v;
	int l;
} mystr;
int main(){
	int n,t,k,hy;
	cin>>n>>t>>k;
	int f[100003]={0};
	mystr m[100003];
	long long int min=100000000004;
	for (int i = 0; i < t; ++i)
	{
		cin>>m[i].u>>m[i].v>>m[i].l;
	}
	for (int i = 0; i < k; ++i)
	{
		cin>>hy;
		f[hy]=1;
	}
	if(k==0){
		cout<<-1<<endl;
		return 0;
	}
	for (int i = 0; i < t; ++i)
	{
		if((f[m[i].u]+f[m[i].v])%2==1)
		{
			if(m[i].l<min)
				min=m[i].l;
		}
	}
	if(min==100000000004){
		cout<<-1<<endl;
		return 0;
	}
	cout<<min<<endl;
}