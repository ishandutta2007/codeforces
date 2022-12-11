#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n,m,i,j,sel,ans,s,a[1000],e;
    char tmp[1001];
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>tmp;
        for (int j=0;j<m;j++)
        {
            switch (tmp[j])
            {case 'G':{s=j;break;}
            case 'S':{e=j;break;}}

        }
        a[i]=e-s;if (a[i]<=0) {cout<<-1;return(0);}
    }
    ans=0;
    do
    {
        sel=1001;
        for (i=0;i<n;i++) if ((a[i]<sel)&&(a[i])) sel=a[i];
        if (sel==1001) {cout<<ans;return(0);}
        ans++;
        for (i=0;i<n;i++) if (a[i]) a[i]-=sel;
    }
    while (1);
}