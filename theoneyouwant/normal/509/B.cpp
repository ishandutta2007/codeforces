#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    cin>>a[0];
    int min=a[0],max=a[0];
    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
        {
            max=a[i];
        }
        if(a[i]<min)
        {
            min=a[i];
        }
    }
    if(max-min>k)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<min;j++)
            {
                cout<<"1"<<" ";
            }
            for(int j=min;j<a[i];j++)
            {
                cout<<j-min+1<<" ";
            }
            cout<<endl;
        }
    }
    
	return 0;
}