#include <iostream>

using namespace std;

int main()
{
    long int n,m,i,tmp,sys,a[100000],inc,tar;
    cin>>n>>m;
    for(i=0;i<n;i++) cin>>a[i];
    inc=0;
    for(i=0;i<m;i++)
    {
        cin>>sys;
        switch(sys)
        {
        case 1:
            {
                cin>>tar>>tmp;
                a[tar-1]=tmp-inc;
                break;
            }
        case 2:
            {
                cin>>tmp;
                inc+=tmp;
                break;
            }
        case 3:{cin>>tar;cout<<(a[tar-1]+inc)<<endl;break;}
        }
    }
}