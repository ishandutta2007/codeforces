#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long int a[n],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if((3+(sum%3))%3 != 0)
    {
        cout<<"0";
    }
    else
    {
        long long int counter=0;
        vector<long long int> v1,v2;
        for(int i=0;i<n-1;i++)
        {
            counter+=a[i];
            if(counter == sum/3)
            {
                v1.push_back(i);
            }
            if(counter == 2*sum/3)
            {
                v2.push_back(i);
            }
        }
        if(sum == 0)
        {
            cout<<(long long int)v1.size()*(v1.size()-1)/2;
        }
        else
        {
            long long int counter1=0, counter2=0;
          for(vector<long long int>::iterator it=v1.begin();it!=v1.end();it++)
        {
            counter2 = 0;
            for(vector<long long int>::iterator it2=v2.begin();it2!=v2.end();it2++)
            {
                if((*it2)<(*it))
                {
                    counter2++;
                }
                else
                {
                    break;
                }
            }
            counter1 = counter1 + v2.size() - counter2;
        }
        cout<<counter1;  
        }
    }
    
	return 0;
}