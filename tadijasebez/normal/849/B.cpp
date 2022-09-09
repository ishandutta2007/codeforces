#include <stdio.h>
#include <vector>
using namespace std;
const int N=1050;
vector<double> k;
vector< pair<int,int> > line;
int x[N];
int main()
{
	int n,i,j,l;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&x[i]);
	for(i=1;i<n;i++) k.push_back((double)(x[i]-x[0])/(i));
	for(j=0;j<k.size();j++)
	{
		line.clear();
		line.push_back(make_pair(0,x[0]));
		for(i=1;i<n;i++)
		{
			if(line.size()>2) break;
			bool ok=false;
			for(l=0;l<line.size();l++)
			{
				if((double)(x[i]-line[l].second)/(i-line[l].first)==k[j])
				{
					line[l]=make_pair(i,x[i]);
					ok=true;
					break;
				}
			}
			if(!ok)
			{
				line.push_back(make_pair(i,x[i]));
			}
		}
		if(line.size()==2)
		{
			printf("Yes\n");
			return 0;
		}
	}
	if(x[2]-x[1]!=x[1]-x[0])
	{
		int f=(x[2]-x[1]);
		bool ok=true;
		for(i=3;i<n;i++)
		{
			if(x[i]-x[i-1]!=f) ok=false;
		}
		if(ok)
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}