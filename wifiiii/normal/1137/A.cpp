#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[1005][1005],aa[1005][1005],aaa[1005][1005],b[1005][1005],c[1005][1005],ans[1005][1005];
int mb[1005],mc[1005],Mb[1005],Mc[1005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(Mb,-0x3f,sizeof(mb));
    memset(Mc,-0x3f,sizeof(mb));
    memset(mb,0x3f,sizeof(mb));
    memset(mc,0x3f,sizeof(mb));
    int n,m;
    cin>>n>>m;
    ii jj cin>>a[i][j];
    ii
    {
        jj aa[i][j]=a[i][j];
        sort(aa[i]+1,aa[i]+1+m);
        int len=unique(aa[i]+1,aa[i]+1+m)-aa[i]-1;
        jj
        {
            b[i][j]=lower_bound(aa[i]+1,aa[i]+1+len,a[i][j])-aa[i];
            mb[i]=min(b[i][j],mb[i]);
            Mb[i]=max(b[i][j],Mb[i]);
        }
    }
    ij
    {
        ji aaa[i][j]=a[j][i];
        sort(aaa[i]+1,aaa[i]+1+n);
        int len=unique(aaa[i]+1,aaa[i]+1+n)-aaa[i]-1;
        ji
        {
            c[j][i]=lower_bound(aaa[i]+1,aaa[i]+1+len,a[j][i])-aaa[i];
            mc[i]=min(c[j][i],mc[i]);
            Mc[i]=max(c[j][i],Mc[i]);
        }
    }
//    cout<<endl;ii {jj cout<<b[i][j]<<" ";cout<<endl;}
//    cout<<endl;ii {jj cout<<c[i][j]<<" ";cout<<endl;}
    ii
    {
        jj
        {
            ans[i][j]=max(b[i][j]-mb[i],c[i][j]-mc[j])+max(Mb[i]-b[i][j],Mc[j]-c[i][j])+1;
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}