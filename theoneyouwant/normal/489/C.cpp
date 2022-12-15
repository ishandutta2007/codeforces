#include <iostream>
using namespace std;

int main() {
	int m,s;
	cin>>m>>s;
	if(s>9*m || s==0)
	{
if(m==1 && s==0)
{
cout<<"0 0";
}
else
{
	    cout<<"-1 -1";
}	}
	else
	{
	    int sum = s;
	    int counter1 = m;
	    int counter2 = 1;
	    while(counter1!=0)
	    {
	        if(s<=9*(m-counter2) && s>=0)
	        {
	            if(s==0)
	            {
	                cout<<"0";
	            }
	            else
	            {
	            if(counter1==m)
	            {
	                cout<<"1";
	                s=s-1;
	            }
	            else
	            {
	            cout<<"0";
	            }}
	        }
	        else
	        {
	            cout<<s-9*(m-counter2);
	            s=s-(s-9*(m-counter2));
	        }
	        counter1--;
	        counter2++;
	    }
	    cout<<" ";
	    counter1 = m;
	    counter2 = 1;
	    s=sum;
	    while(counter1!=0)
	    {
	        if(s>=9)
	        {
	            cout<<"9";
	            s-=9;
	        }
	        else
	        {
	            cout<<s;
	            s=0;
	        }
	        counter1--;
	    }
	}
	return 0;
}