#include <iostream>
using namespace std;

int main() {
    long long int n;
    cin>>n;
    long long int a[n];
    cin>>a[0];
    long long int min=a[0],max=a[0];
    for(long long int i=1;i<n;i++)
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
    long long int b[max+1]= {0};
    long long int score[max+1];
    for(long long int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    score[0]=0;
    score[1]=b[1]*1;
    for(long long int i=2;i<=max;i++)
    {
        if(score[i-2]+b[i]*i>=score[i-1])
        {
            score[i] = score[i-2]+b[i]*i;
        }
        else
        {
            score[i]=score[i-1];
        }
    }
    cout<<score[max];
	// your code goes here
	return 0;
}