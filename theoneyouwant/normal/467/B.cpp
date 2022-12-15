#include <iostream>
using namespace std;

int main() {
    int m,n,k,counter1=0,counter2=0;
    cin>>n>>m>>k;
    int a[m+1];
    for(int i=0;i<m+1;i++)
    {
        cin>>a[i];
    }
    int b[n],c[n];
    for(int i=0;i<n;i++)
    {
        b[i] = a[m]%2;
        a[m]=a[m]/2;
    }
    for(int i=0;i<m;i++)
    {
        counter1=0;
        for(int j=0;j<n;j++)
        {
            c[j]=a[i]%2;
            a[i]=a[i]/2;
            if(c[j]!=b[j])
            {
                counter1+=1;
            }
        }
        if(counter1<=k)
        {
            counter2+=1;
        }
    }
    cout<<counter2;
	return 0;
}