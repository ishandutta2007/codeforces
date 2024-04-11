#include<iostream>
using namespace std;

int main()
{
    int d,sumtime;
    cin>>d>>sumtime;
    long long int min=0,max=0;
    int a[d][2];
    for(int i=0;i<d;i++)
    {
        cin>>a[i][0]>>a[i][1];
        min+=a[i][0];
        max+=a[i][1];
    }
    if(sumtime>=min && sumtime<=max)
    {
        int i=0;
        cout<<"YES"<<endl;
        while(i!=d)
        {
            if(sumtime>=min+a[i][1]-a[i][0])
            {
                cout<<a[i][1]<<" ";
                sumtime-=a[i][1];
            }
            else 
            {
                cout<<a[i][0]+sumtime-min<<" ";
                sumtime=min-a[i][0];
            }
            min-=a[i][0];
            max-=a[i][1];
            i++;
        }
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}