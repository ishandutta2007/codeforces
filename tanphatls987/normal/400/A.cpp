#include <iostream>

using namespace std;

const int t[6]={12,6,4,3,2,1};

int main()
{
    int a[6][12],ans,th,k,i,j,h[6],n;
    char tmp[13];
    cin>>th;
    for (int k=0;k<th;k++)
    {
        for (i=0;i<6;i++) h[i]=0;
        ans=0;
        for(i=0;i<6;i++)
            for(j=0;j<t[i];j++) a[i][j]=0;
        cin>>tmp;
        for(i=0;i<12;i++) {if (tmp[i]!='X') for(j=0;j<6;j++) a[j][i%t[j]]=1;}
        for(i=0;i<6;i++)
        {for(j=0;j<t[i];j++) if (a[i][j]==0) {h[i]=1;ans++;break;}}
        cout<<ans<<" ";
        for(i=0;i<6;i++) if (h[i]==1) cout<<12/t[i]<<"x"<<t[i]<<" ";
        cout<<endl;
    }
}