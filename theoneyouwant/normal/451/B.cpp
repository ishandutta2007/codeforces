#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int j;
    int n;
    cin>>n;
    bool b=0,c=1;
    long long int a[n],z[n],start=1,end=1,posn;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        z[i] = a[i];
    }
    sort(z,z+n);
    for(int i=0;i<n;i++)
    {
        if(b==1)
        {
            if(a[i]==z[i] && a[i]!=z[posn-1])
            {
                continue;
            }
            if(posn<0)
            {
                cout<<"no";
                c=0;
                break;
            }
            if(a[i]!=z[posn-1])
            {
                c=0;
                cout<<"no";
                break;
            }
            posn-=1;
            end = i+1;
        }
        else
        {
            if(a[i]==z[i]) continue;
            for(j=0;j<n;j++)
            {
                if(z[j]==a[i])
                {
                    posn = j;
                    break;
                }
            }
            b=1;
            start= i+1;
            end = i+1;
        }
    }
    if(c==1)
    {
        cout<<"yes"<<endl<<start<<" "<<end;
    }
}