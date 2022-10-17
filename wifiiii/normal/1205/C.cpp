#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
//#define endl '\n'

int a[55][55];
int main()
{
    int n;
    cin>>n;
    int res;
    a[1][1]=1,a[n][n]=0;
    for(int i=3;i<=n;i+=2)
    {
        cout<<"? "<<1<<" "<<i-2<<" "<<1<<" "<<i<<endl;
        cout.flush();
        cin>>res;
        if(res) a[1][i]=a[1][i-2];
        else a[1][i]=1-a[1][i-2];
    }
    for(int j=3;j<=n;j+=2)
    {
        cout<<"? "<<j-2<<" "<<1<<" "<<j<<" "<<1<<endl;
        cout.flush();
        cin>>res;
        if(res) a[j][1]=a[j-2][1];
        else a[j][1]=1-a[j-2][1];
        for(int i=3;i<=n;i+=2)
        {
            if(i==n && j==n) continue;
            cout<<"? "<<j<<" "<<i-2<<" "<<j<<" "<<i<<endl;
            cout.flush();
            cin>>res;
            if(res) a[j][i]=a[j][i-2];
            else a[j][i]=1-a[j][i-2];
        }
    }
    
    cout<<"? 1 1 2 2"<<endl;
    cout.flush();
    cin>>res;
    if(res) a[2][2]=1;
    else a[2][2]=0;
    
    for(int i=4;i<=n;i+=2)
    {
        cout<<"? "<<2<<" "<<i-2<<" "<<2<<" "<<i<<endl;
        cout.flush();
        cin>>res;
        if(res) a[2][i]=a[2][i-2];
        else a[2][i]=1-a[2][i-2];
    }
    
    for(int j=4;j<=n;j+=2)
    {
        cout<<"? "<<j-2<<" "<<2<<" "<<j<<" "<<2<<endl;
        cout.flush();
        cin>>res;
        if(res) a[j][2]=a[j-2][2];
        else a[j][2]=1-a[j-2][2];
        for(int i=4;i<=n;i+=2)
        {
            cout<<"? "<<j<<" "<<i-2<<" "<<j<<" "<<i<<endl;
            cout.flush();
            cin>>res;
            if(res) a[j][i]=a[j][i-2];
            else a[j][i]=1-a[j][i-2];
        }
    }
    
    a[1][2] = 1;
    for(int i=4;i<=n;i+=2)
    {
        cout<<"? "<<1<<" "<<i-2<<" "<<1<<" "<<i<<endl;
        cout.flush();
        cin>>res;
        if(res) a[1][i]=a[1][i-2];
        else a[1][i]=1-a[1][i-2];
    }
    
    for(int j=3;j<=n;j+=2)
    {
        cout<<"? "<<j-2<<" "<<2<<" "<<j<<" "<<2<<endl;
        cout.flush();
        cin>>res;
        if(res) a[j][2]=a[j-2][2];
        else a[j][2]=1-a[j-2][2];
        for(int i=4;i<=n;i+=2)
        {
            cout<<"? "<<j<<" "<<i-2<<" "<<j<<" "<<i<<endl;
            cout.flush();
            cin>>res;
            if(res) a[j][i]=a[j][i-2];
            else a[j][i]=1-a[j][i-2];
        }
    }
    
    cout<<"? 2 1 3 2"<<endl;
    cout.flush();
    cin>>res;
    if(res) a[2][1]=a[3][2];
    else a[2][1]=1-a[3][2];
    
    for(int i=4;i<=n;i+=2)
    {
        cout<<"? "<<i-2<<" "<<1<<" "<<i<<" "<<1<<endl;
        cout.flush();
        cin>>res;
        if(res) a[i][1]=a[i-2][1];
        else a[i][1]=1-a[i-2][1];
    }
    
    for(int i=2;i<=n;i+=2)
    {
        for(int j=3;j<=n;j+=2)
        {
            cout<<"? "<<i<<" "<<j-2<<" "<<i<<" "<<j<<endl;
            cout.flush();
            cin>>res;
            if(res) a[i][j]=a[i][j-2];
            else a[i][j]=1-a[i][j-2];
        }
    }
    
    int b1[55][55],b2[55][55];
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            b1[i][j]=b2[i][j]=a[i][j];
            if((i+j)&1) b2[i][j]=1-a[i][j];
        }
    }
    
    int ok = 0;
    for(int x1=1;x1<=n;++x1)
        for(int y1=1;y1<=n;++y1)
        {
            for(int x2=x1;x2<=n;++x2)
                for(int y2=y1;y2<=n;++y2)
                {
                    if(ok) break;
                    if(x2+y2-x1-y1==3)
                    {
                        int res1=0,res2=0;
                        if(x2-x1==1)
                        {
                            if(b1[x1][y1]==b1[x2][y2] && (b1[x1][y1+1]==b1[x1][y1+2] || b1[x1][y1+1]==b1[x1+1][y1+1]
                                                          || b1[x1+1][y1]==b1[x1+1][y1+1])) res1=1;
                            if(b2[x1][y1]==b2[x2][y2] && (b2[x1][y1+1]==b2[x1][y1+2] || b2[x1][y1+1]==b2[x1+1][y1+1]
                                                          || b2[x1+1][y1]==b2[x1+1][y1+1])) res2=1;
                        }
                        else if(y2-y1==1)
                        {
                            if(b1[x1][y1]==b1[x2][y2] && (b1[x1+1][y1]==b1[x1+2][y1] || b1[x1+1][y1]==b1[x1+1][y1+1]
                                                          || b1[x1][y1+1]==b1[x1+1][y1+1])) res1=1;
                            if(b2[x1][y1]==b2[x2][y2] && (b2[x1+1][y1]==b2[x1+2][y1] || b2[x1+1][y1]==b2[x1+1][y1+1]
                                                          || b2[x1][y1+1]==b2[x1+1][y1+1])) res2=1;
                        }
                        if(res1 != res2)
                        {
                            cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
                            cout.flush();
                            cin>>res;
                            if(res==res2)
                            {
                                for(int i=1;i<=n;++i)
                                    for(int j=1;j<=n;++j)
                                        if((i+j)&1) a[i][j]=1-a[i][j];
                            }
                            ok = 1;
                        }
                    }
                }
        }
    cout<<"!"<<endl;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=n;++j)
            cout<<a[i][j];
        cout<<endl;
    }
}