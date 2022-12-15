#include <iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int prev[100001],difference[100001],counter[100001],first[100001];
	for(int i=0;i<100001;i++)
	{
	    prev[i] = difference[i] = counter[i] = first[i] = -1;
	}
	int a[n];
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	    if(prev[a[i]]==-1)
	    {
	        first[a[i]]=i;
	        prev[a[i]]=i;
	        counter[a[i]]=0;
	        difference[a[i]]=0;
	    }
	    else
	    {
	        if(counter[a[i]]==0)
	        {
	            counter[a[i]]=2;
	            difference[a[i]]=i-prev[a[i]];
	            prev[a[i]]=i;
	        }
	        else
	        {
	            if(difference[a[i]]+prev[a[i]]==i)
	            {
	                counter[a[i]]++;
	            }
	            else
	            {
	                counter[a[i]]+=1000;
	            }
	            prev[a[i]]=i;
	        }
	    }
	}
	int counter1=0;
	
	for(int i=0;i<100001;i++)
	{
	    if((difference[i]!=0 && 1+((prev[i]-first[i])/difference[i]) == counter[i]) || (difference[i]==0))
	    counter1++;
	}
	cout<<counter1<<"\n";
	for(int i=0;i<100001;i++)
	{
	    if((difference[i]!=0 && 1+ ((prev[i]-first[i])/difference[i]) == counter[i]) || (difference[i]==0))
	    cout<<i<<" "<<difference[i]<<"\n";
	}
	return 0;
}