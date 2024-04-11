#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=53;
int a[maxn][maxn];
bool ch[maxn][maxn];
void query(int x1,int y1,int x2,int y2)
{
    ch[x2][y2]=true;
    cout<<"? "<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<endl;
    int ans;
    cin>>ans;
    a[x2][y2]=a[x1][y1]^ans^1;
}
int query1(int x1,int y1,int x2,int y2)
{
    cout<<"? "<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<endl;
    int ans;
    cin>>ans;
    return ans^1;
}
void query2(int x1,int y1,int x2,int y2)
{
    cout<<"? "<<x1+1<<' '<<y1+1<<' '<<x2+1<<' '<<y2+1<<endl;
    int ans;
    cin>>ans;
    a[x1][y1]=a[x2][y2]^ans^1;
}
void getans(int n)
{
    cout<<"! "<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }
    exit(0);
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[i][j]=0;
            ch[i][j]=false;
        }
    }
    a[0][0]=1;
    ch[0][0]=true;
    ch[0][1]=true;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(ch[i][j])
            {
            if((i+1)<n && (j+1)<n && !ch[i+1][j+1])
            {
                query(i,j,i+1,j+1);
            }
            if((i+2)<n && !ch[i+2][j])
            {
                query(i,j,i+2,j);
            }
            if((j+2)<n && !ch[i][j+2])
            {
                query(i,j,i,j+2);
            }
            }
            else
            {
            if((i+1)<n && (j+1)<n && ch[i+1][j+1])
            {
                query2(i,j,i+1,j+1);
            }
            else if((i+2)<n && ch[i+2][j])
            {
                query2(i,j,i+2,j);
            }
            else if((j+2)<n && ch[i][j+2])
            {
                query2(i,j,i,j+2);
            }
            ch[i][j]=true;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            if((i+2)<n && (j+1)<n)
            {
                if((a[i][j]^a[i+2][j+1])==(a[i+1][j]^a[i+2][j]) || (a[i][j]^a[i+2][j+1])==(a[i+1][j]^a[i+1][j+1]) || (a[i][j]^a[i+2][j+1])==(a[i][j+1]^a[i+1][j+1]))
                {
                    int h=query1(i,j,i+2,j+1);
                    if(h^a[i][j]^a[i+2][j+1])
                    {
                        for(int i=0;i<n;++i)
                        {
                            for(int j=0;j<n;++j)
                            {
                                if((i+j)%2==1)
                                {
                                    a[i][j]^=1;
                                }
                            }
                        }
                    }
                    getans(n);
                }
            }
            if((i+1)<n && (j+2)<n)
            {
                if((a[i][j]^a[i+1][j+2])==(a[i][j+1]^a[i][j+2]) || (a[i][j]^a[i+1][j+2])==(a[i][j+1]^a[i+1][j+1]) || (a[i][j]^a[i+1][j+2])==(a[i+1][j]^a[i+1][j+1]))
                {
                    int h=query1(i,j,i+1,j+2);
                    if(h^a[i][j]^a[i+1][j+2])
                    {
                        for(int i=0;i<n;++i)
                        {
                            for(int j=0;j<n;++j)
                            {
                                if((i+j)%2==1)
                                {
                                    a[i][j]^=1;
                                }
                            }
                        }
                    }
                    getans(n);
                }
            }
        }
    }
    return 0;
}