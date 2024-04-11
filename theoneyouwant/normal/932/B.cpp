#include <iostream>
using namespace std;

int main() {
	// your code goes here
	long long int q,l,r,k;
	cin>>q;
	long long int count[10][1000001]={0},b[1000001]={0},z[1000001]={0};
	for(int i=1;i<1000001;i++)
	{
	    if(i<10)
	    {
	        b[i]=i;
	        z[i]=i;
	        count[i][i]++;
	        continue;
	    }
	    else if(i%10==0)
	    {
	        b[i]=b[i/10];
	        z[i]=z[i/10];
	        count[z[i]][i]++;
	        continue;
	    }
	    else
	    {
	        b[i]=(i%10)*b[i/10];
	        z[i]=z[b[i]];
	        count[z[i]][i]++;
	        continue;
	    }
	}
	for(int i=2;i<1000001;i++)
	{
	    for(int j=1;j<10;j++)
	    {
	        count[j][i]=count[j][i]+count[j][i-1];
	    }
	}
	for(int i=0;i<q;i++)
	{
	    cin>>l>>r>>k;
	    cout<<count[k][r]-count[k][l-1]<<endl;
	}
	return 0;
}