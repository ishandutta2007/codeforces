#include <bits/stdc++.h>
using namespace std;
int v[55][55];
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,m,i,j,mx1=0,mx2=0,s=0,cntm1=0,cnt1=0,cnt0=0;
    cin>>n;
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
            v[i][j]=-1;
    m=n;
    v[1][1]=v[1][2]=1;
    v[n][n]=0;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if((i+j)%2 || v[i][j]!=-1)
                continue;
            if(i>1 && j>1 && v[i-1][j-1]!=-1)
            {
                cout<<"? "<<i-1<<' '<<j-1<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i-1][j-1];
                else
                    v[i][j]=1-v[i-1][j-1];
            }
            else
            if(i>2 && v[i-2][j]!=-1)
            {
                cout<<"? "<<i-2<<' '<<j<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i-2][j];
                else
                    v[i][j]=1-v[i-2][j];
            }
            else
            if(j>2 && v[i][j-2]!=-1)
            {
                cout<<"? "<<i<<' '<<j-2<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i][j-2];
                else
                    v[i][j]=1-v[i][j-2];
            }
        }
    }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(v[i][j]!=-1)
                continue;
            if(i>1 && j>1 && v[i-1][j-1]!=-1)
            {
                cout<<"? "<<i-1<<' '<<j-1<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i-1][j-1];
                else
                    v[i][j]=1-v[i-1][j-1];
            }
            else
            if(i>2 && v[i-2][j]!=-1)
            {
                cout<<"? "<<i-2<<' '<<j<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i-2][j];
                else
                    v[i][j]=1-v[i-2][j];
            }
            else
            if(j>2 && v[i][j-2]!=-1)
            {
                cout<<"? "<<i<<' '<<j-2<<' '<<i<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i][j-2];
                else
                    v[i][j]=1-v[i][j-2];
            }
        }
    for(i=1;i<=n;++i)
        for(j=1;j<=n;++j)
        {
            if(v[i][j]==-1)
            {
                cout<<"? "<<i<<' '<<j<<' '<<i<<' '<<j+2<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                    v[i][j]=v[i][j+2];
                else
                    v[i][j]=1-v[i][j+2];
            }
        }
    int okt=-1;
    for(i=1;i<=n-3 && okt==-1;++i)
        for(j=1;j<=n-3 && okt==-1;++j)
        {
            if(v[i][j]==v[i][j+2] && v[i][j+1]==v[i][j+3])
            {
                cout<<"? "<<i<<' '<<j<<' '<<i<<' '<<j+3<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                {
                    if(v[i][j]==v[i][j+3])
                        okt=0;
                    else
                        okt=1;
                }
                else
                {
                    if(v[i][j]==v[i][j+3])
                        okt=1;
                    else
                        okt=0;
                }
            }
            else
            if(v[i][j]==v[i+2][j] && v[i+1][j]==v[i+3][j])
            {
                cout<<"? "<<i<<' '<<j<<' '<<i+3<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                {
                    if(v[i][j]==v[i+3][j])
                        okt=0;
                    else
                        okt=1;
                }
                else
                {
                    if(v[i][j]==v[i+3][j])
                        okt=1;
                    else
                        okt=0;
                }
            }
            else
            if(v[i][j]!=v[i][j+2] && v[i][j+1]!=v[i][j+3])
            {
                cout<<"? "<<i<<' '<<j<<' '<<i<<' '<<j+3<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                {
                    if(v[i][j]==v[i][j+3])
                        okt=0;
                    else
                        okt=1;
                }
                else
                {
                    if(v[i][j]==v[i][j+3])
                        okt=1;
                    else
                        okt=0;
                }
            }
            else
            if(v[i][j]!=v[i+2][j] && v[i+1][j]!=v[i+3][j])
            {
                cout<<"? "<<i<<' '<<j<<' '<<i+3<<' '<<j<<'\n';
                cout.flush();
                int a;
                cin>>a;
                if(a==1)
                {
                    if(v[i][j]==v[i+3][j])
                        okt=0;
                    else
                        okt=1;
                }
                else
                {
                    if(v[i][j]==v[i+3][j])
                        okt=1;
                    else
                        okt=0;
                }
            }
        }
    if(okt==-1)
    {
        for(i=1;i<n;++i)
            for(j=1;j<n;++j)
            {
                if(j<=n-2 && v[i][j]==v[i+1][j+2] && v[i+1][j]==v[i+1][j+1] && v[i+1][j+1]==v[i][j+1] && v[i][j+1]==v[i][j+2] || j<=n-2 && v[i][j]!=v[i+1][j+2] && v[i+1][j]!=v[i+1][j+1] && v[i+1][j+1]!=v[i][j+1] && v[i][j+1]!=v[i][j+2])
                {
                    cout<<"? "<<i<<' '<<j<<' '<<i+1<<' '<<j+2<<'\n';
                    cout.flush();
                    int a;
                    cin>>a;
                    if(a==1)
                    {
                        if(v[i][j]==v[i+1][j+2])
                            okt=0;
                        else
                            okt=1;
                    }
                    else
                    {
                        if(v[i][j]==v[i+1][j+2])
                            okt=1;
                        else
                            okt=0;
                    }
                }
                else
                if(i<=n-2 && v[i][j]==v[i+2][j+1] && v[i][j+1]==v[i+1][j+1] && v[i+1][j+1]==v[i+1][j] && v[i+1][j]==v[i+2][j] || i<=n-2 && v[i][j]!=v[i+2][j+1] && v[i][j+1]!=v[i+1][j+1] && v[i+1][j+1]!=v[i+1][j] && v[i+1][j]!=v[i+2][j])
                {
                    cout<<"? "<<i<<' '<<j<<' '<<i+1<<' '<<j+2<<'\n';
                    cout.flush();
                    int a;
                    cin>>a;
                    if(a==1)
                    {
                        if(v[i][j]==v[i+2][j+1])
                            okt=0;
                        else
                            okt=1;
                    }
                    else
                    {
                        if(v[i][j]==v[i+2][j+1])
                            okt=1;
                        else
                            okt=0;
                    }
                }
            }
    }
    cout<<"!\n";
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=n;++j)
        {
            if((i+j)%2==1)
                v[i][j]=(v[i][j]+okt)%2;
            cout<<v[i][j];
        }
        cout<<'\n';
    }
    cout.flush();
	return 0;
}