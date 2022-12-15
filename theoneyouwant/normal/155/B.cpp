#include<iostream>
#include<algorithm>
using namespace std;

int main()

{
    int n;
    cin>>n;
    int a[n]={0},b[n]={0},counter=1,score=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(b[i]!=0)
        {
            counter--;
            counter+=b[i];
            score+=a[i];
            b[i] = a[i] = 0;
        }
    }
    sort(a,a+n);
    int i=n-1;
        while(counter!=0 && i!=-1)
        {
          score+=a[i];
          counter-=1;
          i--;
        }
        cout<<score;
    return 0;
}