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
#define endl '\n'

char a[2005][2005];
int ans[2005][2005],ans2[2005][2005];
void upd(int x1,int y1,int x2,int y2) //x1<=x2, y1<=y2
{
    if(x1>x2 || y1>y2) return;
    x1=max(x1,1),y1=max(y1,1);
    ans[x2+1][y2+1]++,
    ans[x1][y1]++,
    ans[x1][y2+1]--,
    ans[x2+1][y1]--;
}
int main()
{
    int n,k;
    cin>>n>>k;
    ii ji cin>>a[i][j];
    ii
    {
        int l=0,r=0;
        ji
        {
            if(a[i][j]=='B')
            {
                if(!l) l=j;
                r=j;
            }
        }
        if(!l) upd(1,1,n,n);
        else if(r-l<k) upd(i-k+1,r-k+1,i,l);
    }
    ii
    {
        int l=0,r=0;
        ji
        {
            if(a[j][i]=='B')
            {
                if(!l) l=j;
                r=j;
            }
        }
        if(!l) upd(1,1,n,n);
        else if(r-l<k) upd(r-k+1,i-k+1,l,i);
    }
    int res=0;
    ii ji ans[i][j]=ans[i][j]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1],res=max(res,ans[i][j]);
    cout<<res<<endl;
}